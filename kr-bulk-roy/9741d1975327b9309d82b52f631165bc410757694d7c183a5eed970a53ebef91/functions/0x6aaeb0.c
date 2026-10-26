
void FUN_006aaeb0(int param_1)

{
  int *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 uVar4;
  
  if (in_EAX == (int *)0x0) {
LAB_006aaeeb:
    in_EAX = (int *)0x0;
  }
  else {
    iVar1 = (**(code **)(*in_EAX + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_006aaeeb;
    }
  }
  piVar3 = (int *)in_EAX[6];
  if (piVar3 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar3 + 4))();
    if (iVar1 == 0x12d) goto LAB_006aaf1a;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar3 = (int *)0x0;
LAB_006aaf1a:
  if (piVar3[0x93] == 1) {
    FUN_00404300(&DAT_00c1ae08,1);
    FUN_004041f0(piVar3 + 0x94,0,0xffffffff);
  }
  else {
    if (piVar3[0x93] != 3) {
      return;
    }
    uVar4 = 0xffffffff;
    uVar2 = FUN_006ab620(param_1 + 0x104);
    FUN_00402400(uVar2,uVar4);
  }
  iVar1 = *(int *)(param_1 + 0xf4);
  if (*(char *)(iVar1 + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(iVar1 + 0x168) = 0;
  *(undefined4 *)(iVar1 + 0x160) = 0;
  *(undefined4 *)(iVar1 + 0x164) = 0;
  *(undefined4 *)(iVar1 + 0x14c) = 0;
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  FUN_006aa7f0(param_1);
  return;
}

