
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Iput(class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> >,class std::ios_base &,unsigned short,char *,unsigned int)const
   
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __cdecl
   std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Iput(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,class
   std::ios_base &,wchar_t,char *,unsigned int)const 
   
   Library: Visual Studio 2010 Release */

void Iput(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
         ushort param_6,char *param_7,uint param_8)

{
  char cVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  char ****ppppcVar5;
  rsize_t _DstSize;
  uint uVar6;
  undefined4 *puVar7;
  undefined1 local_5c [4];
  char *local_58;
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  uint local_40;
  int local_3c;
  uint local_38;
  char ***local_34;
  char ***local_30 [5];
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x884d3f;
  local_48 = param_2;
  local_40 = (uint)param_6;
  local_38 = param_8;
  local_4c = param_1;
  uVar4 = FUN_004318d0(local_54);
  local_8 = 0;
  local_44 = (int *)use_facet<>(uVar4);
  local_8 = 0xffffffff;
  FUN_004327c0();
  grouping(local_30);
  cVar1 = *param_7;
  local_8 = 1;
  if ((cVar1 == '+') || (cVar1 == '-')) {
    local_3c = 1;
  }
  else if ((cVar1 == '0') && ((param_7[1] == 'x' || (param_7[1] == 'X')))) {
    local_3c = 2;
  }
  else {
    local_3c = 0;
  }
  ppppcVar5 = (char ****)local_30[0];
  if (local_1c < 0x10) {
    ppppcVar5 = local_30;
  }
  if (*(char *)ppppcVar5 != '\x7f') {
    ppppcVar5 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar5 = local_30;
    }
    if ('\0' < *(char *)ppppcVar5) {
      uVar6 = local_38;
      if (local_1c < 0x10) {
        local_34 = (char ***)local_30;
      }
      else {
        local_34 = local_30[0];
      }
      while (((cVar1 = *(char *)local_34, param_1 = local_4c, cVar1 != '\x7f' && ('\0' < cVar1)) &&
             ((uint)(int)cVar1 < uVar6 - local_3c))) {
        uVar6 = uVar6 - (int)cVar1;
        _DstSize = (local_38 - uVar6) + 1;
        local_58 = param_7 + uVar6;
        _memmove_s(param_7 + uVar6 + 1,_DstSize,local_58,_DstSize);
        *local_58 = '\0';
        local_38 = local_38 + 1;
        if ('\0' < *(char *)((int)local_34 + 1)) {
          local_34 = (char ***)((int)local_34 + 1);
        }
      }
    }
  }
  uVar6 = *(uint *)(param_5 + 0x20);
  if (((*(int *)(param_5 + 0x24) < 0) || ((*(int *)(param_5 + 0x24) < 1 && (uVar6 == 0)))) ||
     (uVar6 <= local_38)) {
    local_34 = (char ***)0x0;
  }
  else {
    local_34 = (char ***)(uVar6 - local_38);
  }
  uVar6 = *(uint *)(param_5 + 0x14) & 0x1c0;
  if (uVar6 != 0x40) {
    if (uVar6 == 0x100) {
      puVar7 = (undefined4 *)Putc(param_1,local_50,param_3,param_4,param_7,local_3c);
      param_7 = param_7 + local_3c;
      local_38 = local_38 - local_3c;
      puVar7 = (undefined4 *)Rep(param_1,local_50,*puVar7,puVar7[1],local_40,local_34);
    }
    else {
      puVar7 = (undefined4 *)Rep(param_1,local_50,param_3,param_4,local_40,local_34);
    }
    param_3 = *puVar7;
    local_34 = (char ***)0x0;
    param_4 = puVar7[1];
  }
  uVar3 = (**(code **)(*local_44 + 8))();
  puVar7 = (undefined4 *)Putgrouped(param_1,local_5c,param_3,param_4,param_7,local_38,uVar3);
  uVar4 = *puVar7;
  uVar2 = puVar7[1];
  *(undefined4 *)(param_5 + 0x20) = 0;
  *(undefined4 *)(param_5 + 0x24) = 0;
  Rep(param_1,local_48,uVar4,uVar2,local_40,local_34);
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

