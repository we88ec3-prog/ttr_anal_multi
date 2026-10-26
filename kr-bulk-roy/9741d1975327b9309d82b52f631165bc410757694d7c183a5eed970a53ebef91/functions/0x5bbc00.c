
void FUN_005bbc00(int param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  
  if (in_EAX != (int *)0x0) {
    iVar2 = (**(code **)(*in_EAX + 4))();
    if (iVar2 == 0x105ce) goto LAB_005bbc36;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_EAX = (int *)0x0;
LAB_005bbc36:
  iVar1 = in_EAX[5];
  iVar2 = *(int *)(param_1 + 0x2c0);
  *(uint *)(iVar2 + 0x110) = (uint)*(byte *)(in_EAX + 6);
  (**(code **)(**(int **)(iVar2 + 0x104) + 0x90))((char)iVar1);
  (**(code **)(**(int **)(iVar2 + 0x104) + 200))();
  (**(code **)(**(int **)(iVar2 + 0x10c) + 0x94))((char)iVar1);
  (**(code **)(**(int **)(iVar2 + 0x10c) + 200))();
  return;
}

