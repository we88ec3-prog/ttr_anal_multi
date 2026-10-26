
int FUN_006fe4c0(int param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  
  if ((*(byte *)(param_1 + 0x38) & 2) != 0) {
    in_EAX = (undefined4 *)FUN_006fe3a0();
  }
  iVar3 = *(int *)(param_1 + 0x14);
  *(undefined4 **)(param_1 + 0x14) = (undefined4 *)(iVar3 + -0x18);
  iVar1 = *(int *)(iVar3 + 0x10);
  puVar2 = *(undefined4 **)(iVar3 + 4);
  *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar3 + -0x18);
  *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar3 + -0xc);
  iVar3 = iVar1;
  for (; (iVar3 != 0 && (in_EAX < *(undefined4 **)(param_1 + 8))); in_EAX = in_EAX + 4) {
    *puVar2 = *in_EAX;
    puVar2[1] = in_EAX[1];
    iVar3 = iVar3 + -1;
    puVar2[2] = in_EAX[2];
    puVar2 = puVar2 + 4;
  }
  for (; 0 < iVar3; iVar3 = iVar3 + -1) {
    puVar2[2] = 0;
    puVar2 = puVar2 + 4;
  }
  *(undefined4 **)(param_1 + 8) = puVar2;
  return iVar1 + 1;
}

