
void FUN_005aa3d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_EAX;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uStack_28;
  undefined4 uStack_20;
  
  if (in_EAX != (int *)0x0) {
    puVar3 = (undefined1 *)(**(code **)(*in_EAX + 4))();
    if (puVar3 == &DAT_000f4284) goto LAB_005aa405;
    uStack_20 = 0x5aa403;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005aa405:
  iVar1 = in_EAX[5];
  piVar5 = in_EAX + 6;
  piVar6 = &uStack_28;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x164);
  *(short *)piVar6 = (short)*piVar5;
  *(undefined1 *)((int)piVar6 + 2) = *(undefined1 *)((int)piVar5 + 2);
  FUN_006b60a0(uVar2,iVar1);
  return;
}

