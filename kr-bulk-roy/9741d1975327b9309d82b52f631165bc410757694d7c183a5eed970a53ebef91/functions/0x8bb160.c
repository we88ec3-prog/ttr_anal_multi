
void FUN_008bb160(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *unaff_EDI;
  int local_8;
  
  puVar1 = *(undefined4 **)(unaff_EDI[1] + 0x60);
  uVar2 = puVar1[2];
  iVar3 = puVar1[3];
  local_8 = 0;
  *unaff_EDI = puVar1[1];
  uVar4 = FUN_008baee0(uVar2,0x28,&local_8);
  if (local_8 == 0) {
    unaff_EDI[0x27] = uVar4;
    if (((*(uint *)*puVar1 & 0x200) == 0) && (iVar5 = FUN_008bb050(uVar2,uVar4), iVar5 != 0)) {
      return;
    }
    if (*(code **)(iVar3 + 0x40) != (code *)0x0) {
      (**(code **)(iVar3 + 0x40))();
    }
  }
  return;
}

