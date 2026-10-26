
void FUN_007bfcc0(void)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  uint *in_EDX;
  undefined4 *puVar6;
  undefined1 local_5c [4];
  uint local_58 [4];
  undefined4 local_48;
  uint local_44;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_24;
  uint local_20;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00914d80;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar6 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar6 + 0x39);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if (((int)in_EDX[1] < (int)puVar6[5]) ||
       (((int)in_EDX[1] <= (int)puVar6[5] && (*in_EDX <= (uint)puVar6[4])))) {
      puVar4 = (undefined4 *)*puVar6;
    }
    else {
      puVar4 = (undefined4 *)puVar6[2];
      puVar6 = puVar2;
    }
    puVar2 = puVar6;
    puVar6 = puVar4;
    cVar1 = *(char *)((int)puVar4 + 0x39);
  }
  local_14 = uVar3;
  if (puVar2 != *(undefined4 **)(in_ECX + 4)) {
    if (((int)puVar2[5] < (int)in_EDX[1]) ||
       (((int)puVar2[5] <= (int)in_EDX[1] && ((uint)puVar2[4] <= *in_EDX)))) goto LAB_007bfdc9;
  }
  local_44 = 0xf;
  local_48 = 0;
  local_58[0] = local_58[0] & 0xffffff00;
  local_8 = 0;
  local_3c = *in_EDX;
  local_38 = in_EDX[1];
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  FUN_00402bb0(local_58);
  local_8 = CONCAT31(local_8._1_3_,1);
  uVar5 = FUN_007c1b60(in_ECX);
  FUN_007c0c50(local_5c,puVar2,uVar5);
  if (0xf < local_20) {
    FUN_0089120c(local_34,uVar3);
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = local_34 & 0xffffff00;
  if (0xf < local_44) {
    FUN_0089120c(local_58[0],uVar3);
  }
LAB_007bfdc9:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

