
void FUN_006bfe90(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  int local_c;
  
  piVar3 = param_1;
  if (param_1[4] == 0x578) {
    if (param_1[2] == *(int *)(*(int *)(in_ECX + 0x84) + 0x20)) {
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      puVar5 = (undefined4 *)0x0;
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[3] = 0;
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[4] = 0xf4428;
        puVar5 = puVar4;
      }
      param_1 = (int *)&DAT_000001ca;
      iVar2 = FUN_005854b0();
      FUN_005740f0(&param_1);
      if (local_c == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)(local_c + 0x10);
      if (7 < *(uint *)(local_c + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_00404b10(0xcf,puVar4,&DAT_00bed1fc,puVar5,in_ECX);
    }
    if (piVar3[2] == *(int *)(*(int *)(in_ECX + 0xd0) + 0x20)) {
      if ((*(uint *)(*(int *)(in_ECX + 200) + 0x28) >> 9 & 1) == 0) {
        iVar2 = FUN_00444960();
        FUN_006d1be0(iVar2 + 0x504,iVar2 + 0x284);
        iVar2 = FUN_0048a590();
        if (iVar2 + 0x24 != iVar2 + 0x14) {
          FUN_0085e680(**(undefined4 **)(iVar2 + 0x28),*(undefined4 **)(iVar2 + 0x28));
          FUN_006d4530(iVar2 + 0x14);
        }
        puVar5 = (undefined4 *)FUN_00891268(0x18);
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf43cc;
          *puVar5 = FoxUI::FXUIEventI1::vftable;
          puVar5[5] = 1;
        }
        FUN_004072a0();
        (**(code **)(**(int **)(in_ECX + 0xc4) + 0x94))(0);
      }
      else {
        iVar2 = FUN_00444960();
        FUN_006d1be0(iVar2 + 0x504,iVar2 + 4);
        iVar2 = FUN_0048a590();
        if (iVar2 + 0x24 != iVar2 + 4) {
          FUN_0085e680(**(undefined4 **)(iVar2 + 0x28),*(undefined4 **)(iVar2 + 0x28));
          FUN_006d4530(iVar2 + 4);
        }
        puVar5 = (undefined4 *)FUN_00891268(0x18);
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf43cc;
          *puVar5 = FoxUI::FXUIEventI1::vftable;
          puVar5[5] = 0;
        }
        FUN_004072a0();
        (**(code **)(**(int **)(in_ECX + 0xc4) + 0x94))(0);
      }
      if (DAT_00fba7a4 != 0) {
        *(undefined4 *)(DAT_00fba7a4 + 0x134) = 1;
      }
      puVar5 = (undefined4 *)FUN_00891268(0x14);
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = FoxUI::FXUIEvent::vftable;
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf43cd;
      }
      FUN_004072a0();
      puVar5 = (undefined4 *)FUN_00891268(0x14);
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = FoxUI::FXUIEvent::vftable;
        puVar5[1] = 0xffffffff;
        puVar5[2] = 0xffffffff;
        puVar5[3] = 0;
        puVar5[4] = 0xf4403;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
    }
  }
  else if (param_1[4] == 0xf4428) {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      piVar3 = (int *)0x0;
    }
    if (piVar3[5] == 0x6a7) {
      *(undefined4 *)(DAT_00fba7a4 + 0xb4) = 1;
      return;
    }
  }
  return;
}

