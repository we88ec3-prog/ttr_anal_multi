
int FUN_008f3fd0(undefined4 *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  uint in_EAX;
  int *piVar4;
  int iVar5;
  uint in_ECX;
  int *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if ((uint)unaff_EDI[1] <= in_ECX) {
    *param_1 = 0;
    return 6;
  }
  if ((in_EAX == 0x1f) || (0x2e < (int)(in_EAX + 1))) {
    in_EAX = *(byte *)(unaff_EDI[2] + in_ECX) & 0x7f;
  }
  puVar1 = (&PTR_DAT_00bebbe0)[in_EAX];
  piVar4 = (int *)unaff_EDI[in_EAX + 4];
  puVar2 = (&PTR_DAT_00bebb70)[*(int *)(puVar1 + 4)];
  iVar5 = 0;
  if (piVar4 == (int *)0x0) {
    uVar3 = *(undefined4 *)(*unaff_EDI + 100);
    piVar4 = (int *)FUN_008baee0(uVar3,*(undefined4 *)(puVar2 + 4),&local_8);
    iVar5 = local_8;
    if (local_8 == 0) {
      *piVar4 = (int)puVar1;
      piVar4[9] = (int)unaff_EDI;
      if (*(code **)(puVar2 + 8) != (code *)0x0) {
        iVar5 = (**(code **)(puVar2 + 8))(piVar4,*unaff_EDI);
        local_8 = 0;
        if (iVar5 != 0) {
          local_8 = iVar5;
          if (*(code **)(puVar2 + 0x10) != (code *)0x0) {
            (**(code **)(puVar2 + 0x10))(piVar4);
          }
          FUN_008b9f80(uVar3,piVar4);
          *param_1 = 0;
          return local_8;
        }
      }
      unaff_EDI[in_EAX + 4] = (int)piVar4;
      iVar5 = local_8;
    }
  }
  *param_1 = piVar4;
  return iVar5;
}

