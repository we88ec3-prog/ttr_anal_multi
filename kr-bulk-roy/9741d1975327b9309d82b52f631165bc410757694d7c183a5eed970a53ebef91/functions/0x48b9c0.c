
void FUN_0048b9c0(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char ****ppppcVar4;
  int *piVar5;
  char ****ppppcVar6;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  char ***local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b7a0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
  local_8 = 0;
  local_14 = uVar2;
  FUN_0048b8c0(local_30);
  if (((local_20 < 5) || (iVar3 = FUN_00440930(local_30,&DAT_00c05650,4), iVar3 != local_20 - 4)) &&
     ((local_20 < 6 || (iVar3 = FUN_00440930(local_30,"locale",6), iVar3 != local_20 - 6)))) {
    ppppcVar6 = (char ****)local_30[0];
    if (local_1c < 0x10) {
      ppppcVar6 = local_30;
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    ppppcVar4 = ppppcVar6;
    do {
      cVar1 = *(char *)ppppcVar4;
      ppppcVar4 = (char ****)((int)ppppcVar4 + 1);
    } while (cVar1 != '\0');
    FUN_00402a70(ppppcVar6,(int)ppppcVar4 - (int)((int)ppppcVar6 + 1));
    iVar3 = local_50;
    local_8 = CONCAT31(local_8._1_3_,1);
    local_58 = FUN_004987f0(local_4c);
    if ((local_58 == *(int *)(iVar3 + 0xc)) || (cVar1 = FUN_0049ae30(), cVar1 != '\0')) {
      local_54 = *(int *)(iVar3 + 0xc);
      piVar5 = &local_54;
    }
    else {
      piVar5 = &local_58;
    }
    iVar3 = *piVar5;
    if (0xf < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 0xf;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffffff00;
    if (iVar3 != *(int *)(local_50 + 0xc)) {
      *param_2 = *(undefined4 *)(iVar3 + 0x28);
      param_2[1] = *(undefined4 *)(iVar3 + 0x2c);
      param_2[2] = *(undefined4 *)(iVar3 + 0x30);
      param_2[3] = *(undefined4 *)(iVar3 + 0x34);
      if (0xf < local_1c) {
        FUN_0089120c(local_30[0]);
      }
      goto LAB_0048bb41;
    }
    *param_2 = 0;
    param_2[1] = 0;
    param_2[2] = 0;
    param_2[3] = 0;
  }
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar2);
  }
LAB_0048bb41:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

