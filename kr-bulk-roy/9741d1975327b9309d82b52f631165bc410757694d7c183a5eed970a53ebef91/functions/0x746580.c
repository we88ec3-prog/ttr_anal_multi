
void FUN_00746580(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_EAX;
  undefined4 *extraout_EDX;
  int *unaff_EDI;
  
  iVar1 = unaff_EDI[0x18];
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 100);
    for (piVar3 = (int *)*piVar2; piVar3 != piVar2; piVar3 = (int *)*piVar3) {
      if ((int *)piVar3[2] == unaff_EDI) {
        if (piVar3 != piVar2) {
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          FUN_0089120c(piVar3);
          *(int *)(iVar1 + 0x68) = *(int *)(iVar1 + 0x68) + -1;
        }
        break;
      }
    }
  }
  unaff_EDI[0x18] = in_EAX;
  iVar1 = *(int *)(in_EAX + 0x24);
  unaff_EDI[9] = iVar1;
  if ((unaff_EDI[0xf] != 0) && ((unaff_EDI[10] & 0x40000U) == 0)) {
    FUN_007486f0(iVar1);
  }
  puVar4 = (undefined4 *)unaff_EDI[0x19];
  puVar5 = (undefined4 *)*puVar4;
  while (puVar5 != puVar4) {
    FUN_007486f0(unaff_EDI[9]);
    puVar5 = (undefined4 *)*extraout_EDX;
  }
  (**(code **)(*unaff_EDI + 0xb4))(param_1);
  FUN_00746f70();
  if ((unaff_EDI[0x18] != 0) && (((int *)unaff_EDI[7])[2] != 6)) {
    (**(code **)(*(int *)unaff_EDI[7] + 0x30))();
  }
  FUN_007464b0(unaff_EDI);
  return;
}

