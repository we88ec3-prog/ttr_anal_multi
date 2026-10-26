
void FUN_00586420(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 8))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 == iVar3) {
    (**(code **)(*param_1 + 0x30))();
    FUN_00406fe0();
    param_1[0x3b] = in_ECX[0x3b];
    pcVar1 = *(code **)(*param_1 + 0x34);
    *(char *)(param_1 + 0x3c) = (char)in_ECX[0x3c];
    (*pcVar1)();
  }
  return;
}

