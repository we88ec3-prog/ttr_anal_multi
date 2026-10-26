
undefined4 FUN_00749f40(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  undefined1 local_8 [4];
  
  if (*(int *)(in_EAX + 0x68) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(**(int **)(in_EAX + 100) + 8);
  }
  if (iVar3 != param_1) {
    if (iVar3 != 0) {
      FUN_00745b80();
    }
    piVar1 = *(int **)(in_EAX + 100);
    piVar2 = (int *)*piVar1;
    while( true ) {
      if (piVar2 == piVar1) {
        return 0;
      }
      if (piVar2[2] == param_1) break;
      piVar2 = (int *)*piVar2;
    }
    if (piVar2 != piVar1) {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
      FUN_0089120c(piVar2);
      *(int *)(in_EAX + 0x68) = *(int *)(in_EAX + 0x68) + -1;
    }
    piVar2 = (int *)**(undefined4 **)(in_EAX + 100);
    while( true ) {
      if (piVar2 == piVar1) {
        FUN_0074a200();
        FUN_00745b80();
        return 1;
      }
      if ((*(uint *)(piVar2[2] + 0x28) >> 0xc & 1) == 0) break;
      piVar2 = (int *)*piVar2;
    }
    FUN_0074d6b0(local_8,piVar2);
    FUN_00745b80();
    return 1;
  }
  return 0;
}

