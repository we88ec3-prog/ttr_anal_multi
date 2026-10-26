
int FUN_008bbfc0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int *unaff_EDI;
  int local_8;
  
  puVar1 = (undefined4 *)unaff_EDI[1];
  uVar2 = *puVar1;
  iVar5 = FUN_008baee0(uVar2,0xc,&local_8);
  if (local_8 != 0) {
    return local_8;
  }
  iVar3 = *unaff_EDI;
  unaff_EDI[3] = iVar3;
  unaff_EDI[4] = *(int *)(iVar3 + 0x24);
  if ((*(int *)(iVar3 + 0x24) == 0x6f75746c) &&
     (pcVar4 = *(code **)(*(int *)(iVar3 + 0x38) + 4), pcVar4 != (code *)0x0)) {
    local_8 = (*pcVar4)(uVar2,unaff_EDI + 0xd);
    if (local_8 != 0) {
      FUN_008b9f80(uVar2,iVar5);
      return local_8;
    }
    unaff_EDI[0xe] = *(int *)(*(int *)(iVar3 + 0x38) + 0x10);
    unaff_EDI[0xf] = *(int *)(iVar3 + 0x28);
    local_8 = 0;
  }
  *(int **)(iVar5 + 8) = unaff_EDI;
  FUN_008ba090(puVar1 + 0x25,iVar5);
  FUN_008b8f10();
  return local_8;
}

