
void FUN_00717500(char *param_1)

{
  byte bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  byte *pbVar6;
  bool bVar7;
  byte local_10c [260];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _strcpy_s((char *)local_10c,0x104,param_1);
  puVar2 = (undefined1 *)FUN_007170d0(local_10c);
  if (puVar2 == (undefined1 *)0x0) {
    (**(code **)(*in_ECX + 0x38))(local_10c);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  *puVar2 = 0;
  if ((int)(puVar2 + 1) - (int)local_10c == 1) {
    (**(code **)(*in_ECX + 4))(local_10c + 1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  pbVar6 = &DAT_00c42c80;
  pbVar3 = local_10c;
  do {
    bVar1 = *pbVar3;
    bVar7 = bVar1 < *pbVar6;
    if (bVar1 != *pbVar6) {
LAB_007175c3:
      iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
      goto LAB_007175c8;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar7 = bVar1 < pbVar6[1];
    if (bVar1 != pbVar6[1]) goto LAB_007175c3;
    pbVar3 = pbVar3 + 2;
    pbVar6 = pbVar6 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_007175c8:
  if (iVar4 == 0) {
    if (in_ECX[1] != 0) {
      (**(code **)(*(int *)in_ECX[1] + 4))(local_10c + 3);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    FID_conflict__wprintf(&DAT_00c442f0);
  }
  else {
    pbVar6 = &DAT_00c41190;
    pbVar3 = local_10c;
    do {
      bVar1 = *pbVar3;
      bVar7 = bVar1 < *pbVar6;
      if (bVar1 != *pbVar6) {
LAB_00717640:
        iVar4 = (1 - (uint)bVar7) - (uint)(bVar7 != 0);
        goto LAB_00717645;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar7 = bVar1 < pbVar6[1];
      if (bVar1 != pbVar6[1]) goto LAB_00717640;
      pbVar3 = pbVar3 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00717645:
    if (iVar4 == 0) {
      (**(code **)(*in_ECX + 4))(local_10c + 2);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    piVar5 = (int *)(**(code **)(*in_ECX + 0x38))(local_10c);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))(puVar2 + 1);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

