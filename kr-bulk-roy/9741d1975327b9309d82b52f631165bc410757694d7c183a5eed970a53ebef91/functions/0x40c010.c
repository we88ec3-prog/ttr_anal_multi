
void FUN_0040c010(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *in_ECX;
  int local_c;
  int local_8;
  
  if (param_1[4] == 0x578) {
    if (param_1[2] == *(int *)(in_ECX[0x41] + 0x20)) {
      param_1 = (int *)FUN_00891268(0x14);
      if (param_1 == (undefined4 *)0x0) {
        param_1 = (undefined4 *)0x0;
      }
      else {
        *param_1 = (int)FoxUI::FXUIEvent::vftable;
        param_1[1] = 0xffffffff;
        param_1[2] = 0xffffffff;
        param_1[3] = 0;
        param_1[4] = 0xf4430;
      }
      local_8 = 0x196;
      iVar2 = FUN_005854b0();
      FUN_005740f0(&local_8);
      if (local_c != *(int *)(iVar2 + 4)) {
        if (*(uint *)(local_c + 0x24) < 8) {
          iVar2 = local_c + 0x10;
        }
        else {
          iVar2 = *(int *)(local_c + 0x10);
        }
        local_c = 0x1de;
        iVar3 = FUN_005854b0();
        FUN_005740f0(&local_c);
        if (local_8 != *(int *)(iVar3 + 4)) {
          puVar4 = (undefined4 *)(local_8 + 0x10);
          if (7 < *(uint *)(local_8 + 0x24)) {
            puVar4 = (undefined4 *)*puVar4;
          }
          FUN_00404b10(0xcf,puVar4,iVar2,param_1);
          return;
        }
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (param_1[2] == *(int *)(in_ECX[0x3d] + 0x20)) {
      FUN_0040c360(in_ECX);
    }
  }
  else if (param_1[4] == 0xf4430) {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      (**(code **)(*in_ECX + 0x16c))(0);
      FUN_0040cb80();
      return;
    }
  }
  return;
}

