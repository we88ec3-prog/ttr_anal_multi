
void FUN_00639d20(void)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_c;
  int local_8;
  
  FUN_0040f060();
  if (DAT_00fba7a4 != (int *)0x0) {
    FUN_0040f060();
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if (iVar3 != 0) {
      FUN_0040f060();
      iVar3 = (**(code **)(*DAT_00fba7a4 + 0x20))();
      bVar1 = *(byte *)(iVar3 + 0x88);
      iVar3 = FUN_00404ba0();
      if ((((bVar1 < 10) &&
           (iVar3 = (uint)bVar1 * 0x210 + *(int *)(iVar3 + 0x6924), *(int *)(iVar3 + 0x5c) != 0)) &&
          (iVar3 != 0)) && ((iVar3 != -500 && (*(int *)(iVar3 + 0x1f8) != *(int *)(iVar3 + 0x1fc))))
         ) {
        puVar4 = (undefined4 *)FUN_00891268(0x14);
        puVar6 = (undefined4 *)0x0;
        if (puVar4 != (undefined4 *)0x0) {
          puVar4[3] = 0;
          *puVar4 = FoxUI::FXUIEvent::vftable;
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[4] = 0xf42bc;
          puVar6 = puVar4;
        }
        iVar3 = FUN_00404aa0();
        uVar8 = 0x197;
        FUN_005854b0(0x197,puVar6,*(undefined4 *)(iVar3 + 0x13c4));
        uVar8 = FUN_00585330(uVar8);
        uVar7 = 0x168;
        FUN_005854b0(0x168,uVar8);
        uVar8 = FUN_00585330(uVar7);
        FUN_00404b10(0xcf,uVar8);
        return;
      }
      local_8 = 0x197;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_8);
      if (local_c == *(int *)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      if (*(uint *)(local_c + 0x24) < 8) {
        iVar3 = local_c + 0x10;
      }
      else {
        iVar3 = *(int *)(local_c + 0x10);
      }
      local_c = 0x16a;
      iVar5 = FUN_005854b0();
      FUN_005740f0(&local_c);
      if (local_8 == *(int *)(iVar5 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar6 = (undefined4 *)(local_8 + 0x10);
      if (7 < *(uint *)(local_8 + 0x24)) {
        puVar6 = (undefined4 *)*puVar6;
      }
      FUN_00404b10(0xca,puVar6,iVar3,0,0);
    }
  }
  return;
}

