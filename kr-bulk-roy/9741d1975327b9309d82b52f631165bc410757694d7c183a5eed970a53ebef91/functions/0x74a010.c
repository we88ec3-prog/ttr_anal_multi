
undefined4 FUN_0074a010(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int unaff_EDI;
  
  iVar6 = param_1;
  if (*(int *)(unaff_EDI + 0x68) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(*(int *)(*(int *)(unaff_EDI + 100) + 4) + 8);
  }
  if (iVar5 != param_1) {
    if (iVar5 != 0) {
      FUN_00745b80();
    }
    piVar1 = *(int **)(unaff_EDI + 100);
    for (piVar2 = (int *)*piVar1; piVar2 != piVar1; piVar2 = (int *)*piVar2) {
      if (piVar2[2] == iVar6) {
        if (piVar2 != piVar1) {
          *(int *)piVar2[1] = *piVar2;
          *(int *)(*piVar2 + 4) = piVar2[1];
          FUN_0089120c(piVar2);
          *(int *)(unaff_EDI + 0x68) = *(int *)(unaff_EDI + 0x68) + -1;
        }
        puVar3 = (undefined4 *)**(undefined4 **)(unaff_EDI + 100);
        while ((puVar3 != *(undefined4 **)(unaff_EDI + 100) &&
               ((uVar4 = *(uint *)(puVar3[2] + 0x28), (uVar4 >> 8 & 1) == 0 ||
                (((uVar4 >> 0x13 & 1) == 0 && ((uVar4 >> 0xd & 1) == 0))))))) {
          puVar3 = (undefined4 *)*puVar3;
        }
        iVar6 = FUN_0074d700(puVar3,puVar3[1],&param_1);
        if (*(int *)(unaff_EDI + 0x68) != 0x3ffffffe) {
          *(int *)(unaff_EDI + 0x68) = *(int *)(unaff_EDI + 0x68) + 1;
          puVar3[1] = iVar6;
          **(int **)(iVar6 + 4) = iVar6;
          FUN_00745b80();
          return 1;
        }
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
    }
  }
  return 0;
}

