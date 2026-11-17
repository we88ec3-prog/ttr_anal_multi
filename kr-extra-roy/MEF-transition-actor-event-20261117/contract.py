"""Offline schema/ordering models only. No network, Client/Lua execution or game output."""
from __future__ import annotations
import struct
from typing import Any, Iterable

def integer(value: Any, lo: int, hi: int, label: str) -> int:
    if type(value) is not int or not lo <= value <= hi:
        raise ValueError(f'{label}: expected integer in [{lo}, {hi}]')
    return value

def relation_message(rows: Iterable[tuple[int, ...]], replace: int = 0) -> bytes:
    """Synthetic 0008 application bytes. Opaque fields retain their raw names."""
    integer(replace, 0, 65535, 'replace')
    data = bytearray(struct.pack('<HH', 8, replace))
    limits = [(0,2**32-1),(0,255),(0,255),(0,2**32-1),(0,2**32-1),
              (0,65535),(0,65535),(0,65535),(-32768,32767)]
    for row in rows:
        if len(row) != 9:
            raise ValueError('0008 row requires nine raw fields')
        values = [integer(x,*limits[i],f'row[{i}]') for i,x in enumerate(row)]
        data.extend(struct.pack('<IBBIIHHHh',*values))
    return bytes(data)

def read_relations(data: bytes) -> tuple[int, list[tuple[int,...]]]:
    if len(data)<4 or (len(data)-4)%22 or struct.unpack_from('<H',data)[0]!=8:
        raise ValueError('strict application shape: 4+22*N, opcode 0008')
    return struct.unpack_from('<H',data,2)[0],list(struct.iter_unpack('<IBBIIHHHh',data[4:]))

def binding_message(relation_key: int, pairs: list[tuple[int,int]]) -> bytes:
    integer(relation_key,0,2**32-1,'relation_key')
    # Original count is signed byte; selected content profile is limited to three slots.
    if not 1 <= len(pairs) <= 3:
        raise ValueError('selected profile uses one to three control slots')
    out=bytearray(struct.pack('<HIb',10,relation_key,len(pairs)))
    for actor,key in pairs:
        out.extend(struct.pack('<HH',integer(actor,0,65535,'world_id'),integer(key,0,65535,'binding_key')))
    return bytes(out)

def binding_dependencies(relation_key:int,pairs:list[tuple[int,int]],relations:set[int],actors:set[int]) -> list[str]:
    problems=[]
    if relation_key not in relations: problems.append('MISSING_RELATION')
    for actor,_ in pairs:
        if actor not in actors: problems.append(f'MISSING_WORLD_ACTOR:{actor}')
    return problems

def order_problems(trace:list[str],required_before:list[list[str]]) -> list[str]:
    errors=[]
    if len(set(trace))!=len(trace): errors.append('DUPLICATE_STEP')
    pos={x:i for i,x in enumerate(trace)}
    for a,b in required_before:
        if a not in pos or b not in pos: errors.append(f'MISSING:{a}->{b}')
        elif pos[a]>=pos[b]: errors.append(f'ORDER:{a}->{b}')
    return errors

def unbound(profile:dict[str,Any]) -> list[str]:
    """Null means unbound, never a native zero or a synthesized official value."""
    return [k for k,v in profile['required_binding'].items() if v is None]

def avatar_model(*,found:bool,variant:int,part_present:bool,old_variant:int|None,
                 render_ptr:bool,render_ready:bool,catalog_allows:bool) -> dict[str,Any]:
    """Derived selected setter model, NOT native execution or guaranteed async apply."""
    integer(variant,0,65535,'variant')
    result={'metadata_variant':None,'selection_variant':old_variant,'dirty_requested':False,
            'visual_success_proven':False}
    if not found: return result
    result['metadata_variant']=variant
    if not render_ptr or not render_ready or not catalog_allows:return result
    if part_present and old_variant==variant:return result
    result['selection_variant']=variant if variant else None
    result['dirty_requested']=True
    return result

def selected_intent(rows:list[dict[str,int]],event:int) -> int|None:
    """501650 last-match policy. A later zero selector also overwrites an earlier one."""
    selected=0
    for row in rows:
        if row['type']==11 and row['event']==event and row['current']<row['required']:
            selected=row['selector']
    return selected or None

def result_pairs(data:bytes) -> list[tuple[int,int,int]]:
    if len(data)<2 or (len(data)-2)%13 or struct.unpack_from('<H',data)[0]!=14:
        raise ValueError('strict 000E shape: 2+13*N')
    return [struct.unpack_from('<HHB',data,p)for p in range(2,len(data),13)]
