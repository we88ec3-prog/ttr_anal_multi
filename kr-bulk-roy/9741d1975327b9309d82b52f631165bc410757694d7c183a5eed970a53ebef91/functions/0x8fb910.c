
int FUN_008fb910(uint param_1,void *param_2)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  uint _Size;
  int local_8;
  
  local_8 = 0;
  if ((*(uint *)(in_ECX + 0x2048) <= param_1) || (iVar1 = FUN_008fb780(), iVar1 == 0)) {
    if (((*(uint *)(in_ECX + 0x2048) < param_1) && (iVar1 = FUN_008fb8c0(), iVar1 != 0)) ||
       (in_EAX == 0)) {
      return 0;
    }
    do {
      _Size = *(int *)(in_ECX + 0x2050) - (int)*(void **)(in_ECX + 0x204c);
      if (in_EAX <= _Size) {
        _Size = in_EAX;
      }
      FID_conflict__memcpy(param_2,*(void **)(in_ECX + 0x204c),_Size);
      param_2 = (void *)((int)param_2 + _Size);
      local_8 = local_8 + _Size;
      *(int *)(in_ECX + 0x204c) = *(int *)(in_ECX + 0x204c) + _Size;
      *(int *)(in_ECX + 0x2048) = *(int *)(in_ECX + 0x2048) + _Size;
      in_EAX = in_EAX - _Size;
    } while ((in_EAX != 0) && (iVar1 = FUN_008fb850(), iVar1 == 0));
  }
  return local_8;
}

