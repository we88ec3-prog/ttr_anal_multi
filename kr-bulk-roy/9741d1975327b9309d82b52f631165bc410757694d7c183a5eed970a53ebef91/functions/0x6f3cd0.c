
void FUN_006f3cd0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_120 [68];
  uint uStack_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_120;
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 == (int *)0x0) {
LAB_006f3df5:
    __security_check_cookie(local_c ^ (uint)auStack_120);
    return;
  }
  if (*(int *)(in_ECX + 0x1124) == 0) {
    _memset((void *)(in_ECX + 0xc),0,0x110);
    __security_check_cookie(local_c ^ (uint)auStack_120);
    return;
  }
  iVar2 = (**(code **)(*piVar1 + 100))(piVar1);
  if (iVar2 < 0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))(*(int **)(in_ECX + 8));
    while (iVar2 == -0x7ff8ffe2) {
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x1c))(*(int **)(in_ECX + 8));
    }
    if ((iVar2 == -0x7ff8ffa9) || (iVar2 == -0x7ff8ffeb)) {
      *(undefined4 *)(in_ECX + 0x1128) = 0;
      _memset((void *)(in_ECX + 0xc),0,0x110);
      goto LAB_006f3df5;
    }
    if (iVar2 == -0x7ff8fffb) goto LAB_006f3e28;
  }
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(*(int **)(in_ECX + 8),0x110,auStack_120);
  if (iVar2 < 0) {
    if ((iVar2 == -0x7ff8ffe2) || (iVar2 == -0x7ff8fff4)) {
      *(undefined4 *)(in_ECX + 0x1128) = 0;
      _memset((void *)(in_ECX + 0xc),0,0x110);
      (**(code **)(**(int **)(in_ECX + 8) + 0x1c))(*(int **)(in_ECX + 8));
      __security_check_cookie(uStack_10 ^ (uint)&stack0xfffffedc);
      return;
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0x1128) = 1;
    puVar3 = auStack_120;
    puVar4 = (undefined4 *)(in_ECX + 0xc);
    for (iVar2 = 0x44; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
LAB_006f3e28:
  __security_check_cookie(local_c ^ (uint)auStack_120);
  return;
}

