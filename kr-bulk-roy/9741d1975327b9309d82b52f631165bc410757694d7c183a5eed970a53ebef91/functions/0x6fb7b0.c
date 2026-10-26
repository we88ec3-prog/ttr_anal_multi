
void FUN_006fb7b0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  undefined4 *in_EDX;
  
  puVar1 = *(undefined4 **)(param_1 + 8);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar2 + 0x10) = *param_3;
  *(undefined4 *)(iVar2 + 0x14) = param_3[1];
  *(undefined4 *)(iVar2 + 0x18) = param_3[2];
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar2 + 0x20) = *in_EDX;
  *(undefined4 *)(iVar2 + 0x24) = in_EDX[1];
  *(undefined4 *)(iVar2 + 0x28) = in_EDX[2];
  iVar2 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar2 + 0x30) = *in_ECX;
  *(undefined4 *)(iVar2 + 0x34) = in_ECX[1];
  *(undefined4 *)(iVar2 + 0x38) = in_ECX[2];
  if (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 8) < 0x41) {
    FUN_006fdcb0();
  }
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x40;
  FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x40,0);
  return;
}

