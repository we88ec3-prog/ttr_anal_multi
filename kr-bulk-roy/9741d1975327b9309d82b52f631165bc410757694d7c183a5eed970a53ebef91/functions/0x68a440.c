
void FUN_0068a440(int param_1)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x80);
  piVar1 = (int *)FUN_00443da0();
  iVar2 = FUN_00443da0();
  FUN_00749970((((*(int *)(in_EAX + 0x34) - *(int *)(iVar3 + 0x34)) - *(int *)(in_EAX + 0x2c)) +
               *(int *)(iVar3 + 0x2c)) / 2 + *piVar1,
               (((*(int *)(in_EAX + 0x38) - *(int *)(in_EAX + 0x30)) - *(int *)(iVar3 + 0x38)) +
               *(int *)(iVar3 + 0x30)) / 2 + *(int *)(iVar2 + 4));
  iVar3 = *(int *)(param_1 + 0x84);
  piVar1 = (int *)FUN_00443da0();
  iVar4 = (((*(int *)(unaff_ESI + 0x34) - *(int *)(iVar3 + 0x34)) - *(int *)(unaff_ESI + 0x2c)) +
          *(int *)(iVar3 + 0x2c)) / 2 + *piVar1;
  iVar2 = FUN_00443da0();
  iVar3 = (((*(int *)(unaff_ESI + 0x38) - *(int *)(unaff_ESI + 0x30)) - *(int *)(iVar3 + 0x38)) +
          *(int *)(iVar3 + 0x30)) / 2 + *(int *)(iVar2 + 4);
  FUN_00749970(iVar4,iVar3);
  FUN_00749970(iVar4,iVar3);
  FUN_00749970(iVar4,iVar3);
  *(int *)(param_1 + 0xd4) = unaff_ESI;
  return;
}

