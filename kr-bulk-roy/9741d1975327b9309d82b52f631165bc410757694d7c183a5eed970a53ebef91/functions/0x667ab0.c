
void FUN_00667ab0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = param_1[4];
  if (iVar1 == 0x578) {
    iVar1 = param_1[2];
    if (iVar1 == *(int *)(in_ECX[0x3d] + 0x20)) {
      FUN_004054c0();
      FUN_0058aee0(0xf4315,*(undefined4 *)in_ECX[0x45],((undefined4 *)in_ECX[0x45])[1]);
      (**(code **)(*in_ECX + 0xd4))();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3e] + 0x20)) {
      FUN_00667ee0();
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x46] + 0x20)) {
LAB_00667bcf:
      FUN_00667080(0);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x47] + 0x20)) {
LAB_00667beb:
      FUN_00667080(1);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x48] + 0x20)) {
LAB_00667c07:
      FUN_00667080(2);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x43] + 0x20)) {
LAB_00667b5b:
      FUN_00667200(in_ECX);
      return;
    }
    if (iVar1 == *(int *)(in_ECX[0x3f] + 0x20)) {
      *(undefined1 *)(in_ECX + 0x4c) = 1;
      FUN_00668240(in_ECX);
    }
  }
  else if (iVar1 == 0x58c) {
    iVar1 = param_1[2];
    if (iVar1 == *(int *)(in_ECX[0x46] + 0x20)) goto LAB_00667bcf;
    if (iVar1 == *(int *)(in_ECX[0x47] + 0x20)) goto LAB_00667beb;
    if (iVar1 == *(int *)(in_ECX[0x48] + 0x20)) goto LAB_00667c07;
    if (iVar1 == *(int *)(in_ECX[0x43] + 0x20)) goto LAB_00667b5b;
  }
  else if (iVar1 == 0xf43de) {
    iVar1 = (**(code **)(*param_1 + 4))();
    if (iVar1 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      param_1 = (int *)0x0;
    }
    if (param_1[5] == 0x6a7) {
      FUN_00667020(in_ECX);
      return;
    }
  }
  return;
}

