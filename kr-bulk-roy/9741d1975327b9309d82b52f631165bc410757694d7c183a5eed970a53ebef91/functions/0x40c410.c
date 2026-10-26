
undefined4 FUN_0040c410(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  int local_c;
  int local_8;
  
  if (param_1 != (undefined4 *)0xd) {
    if ((param_1 != (undefined4 *)0xe) && (param_1 != (undefined4 *)0x2af9)) {
      return 0;
    }
    (**(code **)(*in_ECX + 0xd4))();
    return 1;
  }
  if ((*(uint *)(in_ECX[0x41] + 0x28) >> 7 & 1) != 0) {
    param_1 = (undefined4 *)FUN_00891268(0x14);
    if (param_1 == (undefined4 *)0x0) {
      param_1 = (undefined4 *)0x0;
    }
    else {
      *param_1 = FoxUI::FXUIEvent::vftable;
      param_1[1] = 0xffffffff;
      param_1[2] = 0xffffffff;
      param_1[3] = 0;
      param_1[4] = 0xf4430;
    }
    local_8 = 0x196;
    iVar2 = FUN_005854b0();
    FUN_005740f0(&local_8);
    if (local_c == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    if (*(uint *)(local_c + 0x24) < 8) {
      iVar2 = local_c + 0x10;
    }
    else {
      iVar2 = *(int *)(local_c + 0x10);
    }
    local_c = 0x1de;
    iVar3 = FUN_005854b0();
    FUN_005740f0(&local_c);
    if (local_8 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar5 = (*pcVar1)();
      return uVar5;
    }
    puVar4 = (undefined4 *)(local_8 + 0x10);
    if (7 < *(uint *)(local_8 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    FUN_00404b10(0xcf,puVar4,iVar2,param_1);
  }
  return 1;
}

