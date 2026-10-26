
void FUN_008be0f0(byte *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *in_ECX;
  byte *pbVar5;
  byte *in_EDX;
  int iVar6;
  byte *pbVar7;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  in_ECX[2] = 0;
  if (in_ECX[1] != 0) {
    *(undefined **)*in_ECX = &DAT_00bd7a24;
    *(undefined **)(*in_ECX + 4) = &DAT_00bd7a24;
    *(undefined **)(*in_ECX + 8) = &DAT_00bd7a24;
    *(undefined **)(*in_ECX + 0xc) = &DAT_00bd7a24;
    *(undefined **)(*in_ECX + 0x10) = &DAT_00bd7a24;
  }
  if ((((param_2 != 0) && (*param_1 != 0)) && (in_EDX != (byte *)0x0)) && (*in_EDX != 0)) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    bVar3 = false;
    do {
      bVar1 = *in_EDX;
      if (bVar1 == 0) break;
      if ((bVar1 == 0x2b) && (in_EDX[1] == 0)) {
        bVar3 = true;
      }
      else {
        pbVar5 = (byte *)((int)&local_28 + (uint)(bVar1 >> 3));
        *pbVar5 = *pbVar5 | '\x01' << (bVar1 & 7);
      }
      in_EDX = in_EDX + 1;
    } while (in_EDX != (byte *)0x0);
    iVar6 = 0;
    pbVar5 = param_1;
joined_r0x008be1b6:
    do {
      if ((param_1 + param_2 <= pbVar5) || (*pbVar5 == 0)) goto LAB_008be288;
      bVar1 = *pbVar5;
      pbVar7 = pbVar5;
      while ((bVar1 != 0 &&
             (((int)*(char *)((int)&local_28 + (uint)(*pbVar7 >> 3)) & 1 << (*pbVar7 & 7)) == 0))) {
        pbVar7 = pbVar7 + 1;
        bVar1 = *pbVar7;
      }
      if ((in_ECX[2] == in_ECX[1]) && (iVar6 = FUN_008bdfd0(in_ECX[2] + 1), iVar6 != 0)) break;
      if (pbVar7 <= pbVar5) {
        pbVar5 = &DAT_00bd7a24;
      }
      *(byte **)(*in_ECX + in_ECX[2] * 4) = pbVar5;
      in_ECX[2] = in_ECX[2] + 1;
      if (bVar3) {
        pbVar5 = pbVar7;
        if (*pbVar7 != 0) {
          do {
            if (((int)*(char *)((int)&local_28 + (uint)(*pbVar5 >> 3)) & 1 << (*pbVar5 & 7)) == 0)
            break;
            *pbVar5 = 0;
            pbVar5 = pbVar5 + 1;
          } while (*pbVar5 != 0);
LAB_008be26a:
          bVar2 = pbVar7 < pbVar5;
          pbVar7 = pbVar5;
          if ((bVar2) && (*pbVar5 == 0)) {
            iVar6 = 1;
            goto joined_r0x008be1b6;
          }
        }
      }
      else if (*pbVar7 != 0) {
        *pbVar7 = 0;
        pbVar5 = pbVar7 + 1;
        goto LAB_008be26a;
      }
      iVar6 = 0;
      pbVar5 = pbVar7;
    } while( true );
  }
LAB_008be2db:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
LAB_008be288:
  if (((uint)(iVar6 + in_ECX[2]) < (uint)in_ECX[1]) ||
     (iVar4 = FUN_008bdfd0(iVar6 + in_ECX[2] + 1), iVar4 == 0)) {
    if (iVar6 != 0) {
      *(undefined **)(*in_ECX + in_ECX[2] * 4) = &DAT_00bd7a24;
      in_ECX[2] = in_ECX[2] + 1;
    }
    *(undefined4 *)(*in_ECX + in_ECX[2] * 4) = 0;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  goto LAB_008be2db;
}

