
void FUN_0044c370(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if ((char)in_ECX[0x50] == '\0') {
    FUN_00749d00();
    (**(code **)(*in_ECX + 200))();
    (**(code **)(*(int *)in_ECX[0x41] + 0x94))(1);
    (**(code **)(*(int *)in_ECX[0x41] + 200))();
    iVar4 = in_ECX[0x49];
    iVar3 = in_ECX[0x4b];
    iVar2 = in_ECX[0x42];
    iVar1 = ((in_ECX[0x4a] - in_ECX[0x48]) / 2 - *(int *)(iVar2 + 8)) + in_ECX[0x48];
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar1;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar1;
    iVar4 = ((iVar3 - iVar4) / 2 + iVar4) - *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar4;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar4;
    FUN_00746f70();
    iVar4 = in_ECX[0x4d];
    iVar3 = in_ECX[0x4f];
    iVar2 = in_ECX[0x43];
    iVar1 = ((in_ECX[0x4e] - in_ECX[0x4c]) / 2 - *(int *)(iVar2 + 8)) + in_ECX[0x4c];
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar1;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar1;
    iVar4 = ((iVar3 - iVar4) / 2 + iVar4) - *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar4;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar4;
    FUN_00746f70();
    iVar4 = in_ECX[0x42];
    iVar2 = in_ECX[0x48] - *(int *)(iVar4 + 8);
    iVar3 = in_ECX[0x49];
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
    iVar3 = iVar3 - *(int *)(iVar4 + 0xc);
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
    FUN_00746f70();
    iVar4 = in_ECX[0x43];
    iVar2 = in_ECX[0x4c] - *(int *)(iVar4 + 8);
    iVar3 = in_ECX[0x4d];
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
    iVar3 = iVar3 - *(int *)(iVar4 + 0xc);
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
    FUN_00746f70();
    (**(code **)(*(int *)in_ECX[0x42] + 200))();
    (**(code **)(*(int *)in_ECX[0x43] + 200))();
    piVar5 = in_ECX + 0x3c;
    iVar4 = 6;
    do {
      (**(code **)(*(int *)*piVar5 + 0x90))(1);
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_00760c80();
    return;
  }
  if ((char)in_ECX[0x50] == '\x01') {
    FUN_00749d00();
    (**(code **)(*in_ECX + 200))();
    (**(code **)(*(int *)in_ECX[0x41] + 0x94))(0);
    (**(code **)(*(int *)in_ECX[0x41] + 200))();
    iVar4 = in_ECX[0x42];
    iVar3 = in_ECX[0x49];
    iVar2 = in_ECX[0x48] - *(int *)(iVar4 + 8);
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
    iVar3 = (iVar3 + -0x28) - *(int *)(iVar4 + 0xc);
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
    FUN_00746f70();
    iVar4 = in_ECX[0x43];
    iVar3 = in_ECX[0x4d];
    iVar2 = in_ECX[0x4c] - *(int *)(iVar4 + 8);
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
    *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
    iVar3 = (iVar3 + -0x28) - *(int *)(iVar4 + 0xc);
    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
    *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
    FUN_00746f70();
    (**(code **)(*(int *)in_ECX[0x42] + 200))();
    (**(code **)(*(int *)in_ECX[0x43] + 200))();
    piVar5 = in_ECX + 0x3c;
    iVar4 = 6;
    do {
      (**(code **)(*(int *)*piVar5 + 0x90))(0);
      piVar5 = piVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    FUN_00760c80();
    return;
  }
  FUN_00749d00();
  (**(code **)(*in_ECX + 200))();
  (**(code **)(*(int *)in_ECX[0x41] + 0x94))(0);
  (**(code **)(*(int *)in_ECX[0x41] + 200))();
  iVar4 = in_ECX[0x42];
  iVar3 = in_ECX[0x49];
  iVar2 = in_ECX[0x48] - *(int *)(iVar4 + 8);
  *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
  *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
  iVar3 = (iVar3 + -0x28) - *(int *)(iVar4 + 0xc);
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
  FUN_00746f70();
  iVar4 = in_ECX[0x43];
  iVar3 = in_ECX[0x4d];
  iVar2 = in_ECX[0x4c] - *(int *)(iVar4 + 8);
  *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + iVar2;
  *(int *)(iVar4 + 0x10) = *(int *)(iVar4 + 0x10) + iVar2;
  iVar3 = (iVar3 + -0x28) - *(int *)(iVar4 + 0xc);
  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + iVar3;
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + iVar3;
  FUN_00746f70();
  (**(code **)(*(int *)in_ECX[0x42] + 200))();
  (**(code **)(*(int *)in_ECX[0x43] + 200))();
  piVar5 = in_ECX + 0x3c;
  iVar4 = 6;
  do {
    (**(code **)(*(int *)*piVar5 + 0x90))(1);
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_00760c80();
  return;
}

