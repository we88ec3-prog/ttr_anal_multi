
void FUN_00431db0(void)

{
  int in_ECX;
  _Lockit local_8 [4];
  
  std::_Lockit::_Lockit(local_8,0);
  if (*(int *)(in_ECX + 4) != -1) {
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  }
  FUN_0087dd6f();
  return;
}

