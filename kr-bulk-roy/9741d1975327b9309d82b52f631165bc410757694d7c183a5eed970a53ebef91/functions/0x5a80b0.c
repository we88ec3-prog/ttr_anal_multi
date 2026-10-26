
void FUN_005a80b0(int param_1)

{
  HWND hWnd;
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  UINT Msg;
  WPARAM wParam;
  undefined4 uVar5;
  LPARAM lParam;
  int local_78;
  int local_74;
  undefined1 local_70 [104];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf43db:
    FUN_005966c0();
    break;
  case 0xf43dc:
    FUN_00596830(in_ECX);
    break;
  case 0xf43fe:
    FUN_005974d0(in_ECX,0);
    break;
  case 0xf43ff:
    FUN_005978d0(in_ECX);
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4400:
    iVar3 = FUN_004068c0();
    if (*(int *)(iVar3 + 0x14) == 0x6a5) {
      lParam = 1;
      wParam = 0;
      Msg = 0x10;
      hWnd = (HWND)FUN_006dfd60();
      PostMessageW(hWnd,Msg,wParam,lParam);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    break;
  case 0xf4418:
    iVar3 = FUN_005a9fd0();
    puVar1 = (undefined4 *)(iVar3 + 0x14);
    if (7 < *(uint *)(iVar3 + 0x28)) {
      puVar1 = (undefined4 *)*puVar1;
    }
    FUN_0066e440(*(undefined4 *)(in_ECX + 0x138),puVar1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  case 0xf4419:
    iVar3 = FUN_00412ab0();
    if (*(int *)(iVar3 + 0x14) != 0) {
      FUN_006ee1f0();
      FUN_0066e440(*(undefined4 *)(in_ECX + 0x138),local_70);
      iVar3 = 0x66;
      puVar2 = local_70;
      do {
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    break;
  case 0xf441a:
    iVar3 = FUN_00412ab0();
    *(undefined4 *)(*(int *)(in_ECX + 0x144) + 0x5ac) = *(undefined4 *)(iVar3 + 0x14);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  case 0xf441b:
    iVar3 = FUN_00412b10();
    local_78 = iVar3;
    (**(code **)(**(int **)(in_ECX + 0x148) + 0xd4))();
    (**(code **)(**(int **)(in_ECX + 0x14c) + 0xd4))();
    uVar5 = *(undefined4 *)(iVar3 + 0x14);
    FUN_00461dd0(uVar5);
    iVar3 = FUN_00401040(uVar5);
    if (iVar3 != 0) {
      local_78 = *(int *)(local_78 + 0x18);
      FUN_00401210(&local_78);
      if ((local_74 != *(int *)(iVar3 + 0x60)) && ((int *)(local_74 + 0x10) != (int *)0x0)) {
        FUN_00462010(*(undefined4 *)(in_ECX + 0x14c));
        FUN_00444ad0();
        FUN_00498020();
        FUN_00444ad0();
        FUN_00498020();
        local_74 = *(int *)(local_74 + 0x10);
        piVar4 = (int *)FUN_0044d680();
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x24))(local_74);
        }
        FUN_00759ac0(0);
        FUN_00759ac0(1);
        (**(code **)(**(int **)(in_ECX + 0x138) + 0xd0))();
        (**(code **)(**(int **)(in_ECX + 0x150) + 0xd0))();
      }
    }
    break;
  case 0xf442a:
    FUN_005a84b0();
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

