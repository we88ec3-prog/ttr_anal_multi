
void FUN_008ec2a0(void)

{
  int iVar1;
  int *unaff_EBX;
  int *piVar2;
  int *piVar3;
  
  iVar1 = FUN_008ebe70(0);
  if (iVar1 == 0) {
    piVar2 = unaff_EBX + 0x24;
    piVar3 = unaff_EBX + 9;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = unaff_EBX + 0x24;
    piVar3 = unaff_EBX + 0x12;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    piVar2 = unaff_EBX + 0x24;
    piVar3 = unaff_EBX + 0x1b;
    for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar3 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar3 = piVar3 + 1;
    }
    *(undefined2 *)(unaff_EBX + 0x56) = 1;
    *(undefined2 *)(unaff_EBX + 0x57) = 1;
    *(undefined4 *)((int)unaff_EBX + 0x126) = 0x4000;
    *(undefined4 *)((int)unaff_EBX + 0x12a) = *(undefined4 *)((int)unaff_EBX + 0x126);
    *(undefined4 *)((int)unaff_EBX + 0x122) = *(undefined4 *)((int)unaff_EBX + 0x126);
    unaff_EBX[0x4e] = 1;
    unaff_EBX[0x4c] = 1;
    *(undefined2 *)((int)unaff_EBX + 0x15a) = 1;
    unaff_EBX[4] = 0;
    unaff_EBX[0x6b] = 0;
    (**(code **)(*unaff_EBX + 0x28c))();
  }
  return;
}

