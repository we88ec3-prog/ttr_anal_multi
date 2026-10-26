
size_t FUN_00719d20(void *param_1,size_t param_2)

{
  int iVar1;
  int in_ECX;
  size_t _Size;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (*(int *)(in_ECX + 8) < (int)(iVar1 + param_2)) {
    _Size = *(int *)(in_ECX + 8) - iVar1;
    if (_Size != 0) {
      FID_conflict__memcpy(param_1,(void *)(*(int *)(in_ECX + 4) + iVar1),_Size);
      *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + _Size;
    }
    *(undefined1 *)(in_ECX + 0x10) = 1;
    return _Size;
  }
  FID_conflict__memcpy(param_1,(void *)(*(int *)(in_ECX + 4) + iVar1),param_2);
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_2;
  return param_2;
}

