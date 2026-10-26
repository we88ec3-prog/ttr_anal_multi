
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00807b40(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  ushort *in_EDX;
  uint uVar9;
  size_t _Size;
  ushort *_Dst;
  uint *puVar10;
  ushort *puVar11;
  undefined4 uVar12;
  undefined1 auStack_203c [4];
  ushort *local_2038;
  int local_2034;
  uint local_2030;
  int local_202c;
  ushort *local_2028;
  undefined4 local_2024;
  undefined2 local_2020;
  ushort local_1020 [2050];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_14 = ExceptionList;
  local_c = 0xffffffff;
  puStack_10 = &LAB_009098be;
  local_1c = DAT_00d61f20 ^ (uint)auStack_203c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffdfb8;
  ExceptionList = &local_14;
  *(int *)(in_EDX + 0x2800) = *(int *)(in_EDX + 0x2800) + in_ECX;
  uVar5 = *(int *)(in_EDX + 0x2800) - (int)in_EDX;
  local_2038 = in_EDX;
  local_2028 = param_1;
  while (_Dst = local_2038, 3 < uVar5) {
    uVar1 = *in_EDX;
    if ((uVar1 == 0) || (0x1000 < uVar1)) goto LAB_00807e1f;
    local_2034 = 0;
    local_2030 = 0;
    uVar2 = in_EDX[1];
    local_202c = 4;
    if (uVar2 == 0x2633) {
      local_2034 = 1;
      local_202c = 8;
    }
    else if (uVar2 == 0xbbb) {
      local_2030 = 1;
      local_202c = 6;
    }
    else if ((uVar2 == 0x1a68) || (uVar2 == 0x22d7)) {
      local_202c = 4;
    }
    iVar8 = local_202c;
    if ((int)uVar5 < (int)((uint)uVar1 + local_202c)) break;
    if ((DAT_00fe3354 & 1) == 0) {
      DAT_00fe3354 = DAT_00fe3354 | 1;
      local_c = 0;
      FUN_00807120(uVar4);
      _atexit((_func_4879 *)&LAB_00bd0b90);
      local_c = 0xffffffff;
    }
    local_2024 = (uint *)FUN_008075b0();
    puVar11 = (ushort *)(iVar8 + (int)in_EDX);
    uVar5 = (uint)*in_EDX;
    _Dst = local_2038;
    if ((((puVar11 < local_2038) || (local_2038 + 0x2800 <= puVar11)) ||
        ((ushort *)(uVar5 + (int)puVar11) < local_2038)) ||
       (local_2038 + 0x2800 <= (ushort *)(uVar5 + (int)puVar11))) break;
    if (local_2034 == 0) {
      if (local_2030 != 0) {
        local_2020._0_1_ = (byte)*puVar11 ^ 0xb6;
        local_2030 = (uint)(byte)local_2020;
        uVar7 = 1;
        uVar6 = local_2030;
        if (1 < uVar5) {
          do {
            bVar3 = *(byte *)(uVar7 + (int)puVar11) ^ *(byte *)((int)&local_2024 + uVar7 + 3);
            uVar9 = uVar7 + 1;
            *(byte *)((int)&local_2020 + uVar7) = bVar3;
            uVar6 = (uint)(ushort)((short)uVar6 + (ushort)bVar3);
            uVar7 = uVar9;
          } while (uVar9 < uVar5);
        }
        if (in_EDX[2] != (ushort)uVar6) goto LAB_00807d7f;
        puVar11 = &local_2020;
      }
LAB_00807d7a:
      FUN_00807e50(puVar11);
    }
    else {
      local_2020._0_1_ = (byte)*puVar11 ^ 0x7c;
      uVar6 = 1;
      if (1 < uVar5) {
        do {
          uVar7 = uVar6 + 1;
          *(byte *)((int)&local_2020 + uVar6) =
               *(byte *)((int)puVar11 + uVar6) ^ *(byte *)((int)&local_2024 + uVar6 + 3);
          uVar6 = uVar7;
        } while (uVar7 < uVar5);
      }
      local_2034 = 0x1000;
      iVar8 = FUN_00727190(local_1020);
      if (iVar8 == 0) {
        puVar11 = local_1020;
        goto LAB_00807d7a;
      }
    }
LAB_00807d7f:
    *local_2024 = (uint)local_2028;
    if (local_2024[1] == 0) {
      puVar10 = local_2024;
      FUN_00804310(local_2024);
      FUN_008076f0(puVar10);
    }
    else {
      uVar12 = *(undefined4 *)(local_2028 + 0x5040);
      puVar10 = local_2024;
      FUN_00489920(local_2024,uVar12);
      FUN_008040a0(puVar10,uVar12);
    }
    in_EDX = (ushort *)((int)in_EDX + (uint)*in_EDX + local_202c);
    uVar5 = *(int *)(local_2038 + 0x2800) - (int)in_EDX;
  }
  local_2028 = _Dst + 0x2800;
  _Size = *(int *)(_Dst + 0x2800) - (int)in_EDX;
  if (((_Dst <= in_EDX) && (in_EDX < local_2028)) &&
     ((_Dst <= (ushort *)(_Size + (int)in_EDX) &&
      (((ushort *)(_Size + (int)in_EDX) < local_2028 && (-1 < (int)_Size)))))) {
    FID_conflict__memcpy(_Dst,in_EDX,_Size);
    *(byte **)local_2028 = (byte *)((int)_Dst + _Size);
  }
LAB_00807e1f:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_203c);
  return;
}

