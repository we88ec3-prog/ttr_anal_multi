
void FUN_007567d0(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  if (in_ECX[9] != 0) {
    if (in_ECX[0x18] != 0) {
      FUN_00443da0();
      FUN_00443da0();
    }
    iVar1 = FUN_008fed10();
    iVar2 = FUN_008fed10();
    (**(code **)(*in_ECX + 0xbc))
              (iVar1,iVar2,(in_ECX[4] - in_ECX[2]) + iVar1,(in_ECX[5] - in_ECX[3]) + iVar2);
    if ((in_ECX[7] != 0) && (*(int *)(in_ECX[7] + 8) == 0x191)) {
      (**(code **)(*in_ECX + 0xb4))(0x191);
    }
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0x13c;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

