
undefined4 FUN_004cebf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x42c) != 0) {
    FUN_007beae0();
  }
  if (*(int *)(in_ECX + 0x430) != 0) {
    FUN_007beae0();
  }
  FUN_004c8360();
  if ((*(int *)(in_ECX + 0x424) != 0) && (*(int *)(*(int *)(in_ECX + 0x424) + 0x24) != 0)) {
    FUN_007be5f0();
  }
  return 0;
}

