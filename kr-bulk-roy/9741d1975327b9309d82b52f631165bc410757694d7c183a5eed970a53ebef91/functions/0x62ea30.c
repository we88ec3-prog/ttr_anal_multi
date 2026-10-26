
void FUN_0062ea30(undefined4 *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int local_c;
  int local_8;
  
  iVar3 = (int)param_1;
  iVar5 = *(int *)(*(int *)((int)param_1 + 0x110) + 0xcc);
  if (iVar5 != 0) {
    iVar5 = *(int *)(iVar5 + 0xdc);
    iVar6 = -1;
    if (iVar5 != 0) {
      iVar6 = *(int *)(iVar5 + 0x20);
    }
    if (iVar6 != -1) {
      iVar5 = *(int *)((int)param_1 + 0xf4);
      if (iVar5 == 0) {
        puVar4 = (undefined4 *)FUN_00891268(0x1c);
        if (puVar4 == (undefined4 *)0x0) {
          param_1 = (undefined4 *)0x0;
        }
        else {
          uVar1 = *(undefined4 *)((int)param_1 + 0xf4);
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf438d;
          *puVar4 = FoxUI::FXUIEventI2::vftable;
          puVar4[5] = uVar1;
          puVar4[6] = iVar6;
          param_1 = puVar4;
        }
        local_8 = 0x196;
        iVar5 = FUN_005854b0();
        FUN_005740f0(&local_8);
        if (local_c == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        if (*(uint *)(local_c + 0x24) < 8) {
          iVar5 = local_c + 0x10;
        }
        else {
          iVar5 = *(int *)(local_c + 0x10);
        }
        local_c = 0x1d;
        iVar6 = FUN_005854b0();
        FUN_005740f0(&local_c);
        if (local_8 == *(int *)(iVar6 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        puVar4 = (undefined4 *)(local_8 + 0x10);
        if (7 < *(uint *)(local_8 + 0x24)) {
          puVar4 = (undefined4 *)*puVar4;
        }
        FUN_00404b10(0xcf,puVar4,iVar5,param_1,iVar3);
        return;
      }
      if (iVar5 == 1) {
        FUN_0062ed60();
        return;
      }
      if (iVar5 == 2) {
        FUN_0062f050(iVar6);
      }
    }
  }
  return;
}

