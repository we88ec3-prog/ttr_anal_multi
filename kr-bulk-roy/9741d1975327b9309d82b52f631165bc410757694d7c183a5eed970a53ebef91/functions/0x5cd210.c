
void FUN_005cd210(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  
  puVar5 = (undefined4 *)(unaff_EDI + 0x13c);
  iVar4 = 6;
  do {
    if (*(char *)(unaff_EDI + 0x37c) == '\0') {
      (**(code **)(*(int *)puVar5[-6] + 0x94))(0);
      (**(code **)(*(int *)*puVar5 + 0x94))(0);
      (**(code **)(*(int *)puVar5[6] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0xc] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x3d] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x43] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x4b] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x51] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x31] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x37] + 0x94))(1);
      iVar2 = *(int *)(unaff_EDI + 0x348);
      iVar1 = (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 0x14)) + 0x88;
    }
    else {
      (**(code **)(*(int *)puVar5[-6] + 0x94))(1);
      (**(code **)(*(int *)*puVar5 + 0x94))(1);
      (**(code **)(*(int *)puVar5[6] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0xc] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x3d] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x43] + 0x94))(1);
      (**(code **)(*(int *)puVar5[0x4b] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x51] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x31] + 0x94))(0);
      (**(code **)(*(int *)puVar5[0x37] + 0x94))(0);
      iVar2 = *(int *)(unaff_EDI + 0x348);
      iVar1 = (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 0x14)) + 0x3e;
    }
    iVar3 = 0x248 - *(int *)(iVar2 + 8);
    *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar3;
    *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar3;
    iVar1 = iVar1 - *(int *)(iVar2 + 0xc);
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar1;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar1;
    FUN_00746f70();
    puVar5 = puVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

