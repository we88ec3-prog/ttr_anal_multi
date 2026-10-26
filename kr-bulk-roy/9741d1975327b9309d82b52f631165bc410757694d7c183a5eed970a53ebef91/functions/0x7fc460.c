
void FUN_007fc460(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  iVar4 = *(int *)(in_ECX + 0x34);
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x28) = *param_1;
    *(undefined4 *)(iVar4 + 0x2c) = param_1[1];
    *(undefined4 *)(iVar4 + 0x30) = param_1[2];
    iVar4 = *(int *)(iVar4 + 0x10);
    *(undefined4 *)(iVar4 + 0x68) = *param_1;
    *(undefined4 *)(iVar4 + 0x6c) = param_1[1];
    *(undefined4 *)(iVar4 + 0x70) = param_1[2];
    *(undefined4 *)(iVar4 + 0xc0) = 0;
    iVar4 = *(int *)(in_ECX + 0x34);
    uVar1 = param_1[4];
    uVar2 = param_1[5];
    uVar3 = param_1[6];
    *(undefined4 *)(iVar4 + 0x34) = param_1[3];
    *(undefined4 *)(iVar4 + 0x38) = uVar1;
    *(undefined4 *)(iVar4 + 0x3c) = uVar2;
    *(undefined4 *)(iVar4 + 0x40) = uVar3;
    FUN_0077efc0();
    uVar1 = param_1[7];
    uVar2 = param_1[8];
    uVar3 = param_1[9];
    iVar4 = *(int *)(in_ECX + 0x34);
    *(undefined4 *)(iVar4 + 0x44) = uVar1;
    *(undefined4 *)(iVar4 + 0x48) = uVar2;
    *(undefined4 *)(iVar4 + 0x4c) = uVar3;
    FUN_0077ef50(uVar1,uVar2,uVar3);
  }
  return;
}

