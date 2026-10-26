
int FUN_00728db0(void)

{
  void *in_EAX;
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (in_EAX != (void *)0x0) {
    if (*(void **)((int)in_EAX + 0x50) != (void *)0x0) {
      _free(*(void **)((int)in_EAX + 0x50));
    }
    if (*(int *)((int)in_EAX + 0x1c) != 0) {
      if (*(char *)((int)in_EAX + 0x5c) == 'w') {
        iVar3 = FUN_0072a1e0();
      }
      else if (*(char *)((int)in_EAX + 0x5c) == 'r') {
        iVar3 = FUN_00728940();
      }
    }
    if (((*(FILE **)((int)in_EAX + 0x40) != (FILE *)0x0) &&
        (iVar1 = _fclose(*(FILE **)((int)in_EAX + 0x40)), iVar1 != 0)) &&
       (piVar2 = __errno(), *piVar2 != 0x1d)) {
      iVar3 = -1;
    }
    if (*(int *)((int)in_EAX + 0x38) < 0) {
      iVar3 = *(int *)((int)in_EAX + 0x38);
    }
    if (*(void **)((int)in_EAX + 0x44) != (void *)0x0) {
      _free(*(void **)((int)in_EAX + 0x44));
    }
    if (*(void **)((int)in_EAX + 0x48) != (void *)0x0) {
      _free(*(void **)((int)in_EAX + 0x48));
    }
    if (*(void **)((int)in_EAX + 0x54) != (void *)0x0) {
      _free(*(void **)((int)in_EAX + 0x54));
    }
    _free(in_EAX);
    return iVar3;
  }
  return -2;
}

