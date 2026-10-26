
void FUN_0070dd50(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  uVar1 = FUN_0070d950();
  uVar3 = *(undefined4 *)(in_EAX + 0x30);
  iVar2 = FUN_0070dc60(uVar3,uVar1,param_1,1);
  if (iVar2 == 8) {
    local_10 = 4;
    local_18[0] = uVar1;
    uVar3 = FUN_00712090(uVar3,local_18);
    *(undefined4 *)(param_1 + 8) = uVar3;
  }
  return;
}

