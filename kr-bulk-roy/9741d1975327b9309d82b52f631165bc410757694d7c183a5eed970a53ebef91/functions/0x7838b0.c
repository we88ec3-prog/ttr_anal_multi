
void FUN_007838b0(void)

{
  int iVar1;
  int in_EAX;
  int *unaff_EDI;
  _Lockit local_8 [4];
  
  iVar1 = **(int **)(in_EAX + 0x38);
  *unaff_EDI = iVar1;
  std::_Lockit::_Lockit(local_8,0);
  if (*(int *)(iVar1 + 4) != -1) {
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
  }
  FUN_0087dd6f();
  return;
}

