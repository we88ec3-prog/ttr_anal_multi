
uint FUN_00872d90(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  
  uVar1 = *(int *)(in_ECX + 0x188) - *(int *)(in_ECX + 0x184) >> 2;
  if (uVar1 == 0) {
    return 0;
  }
  uVar2 = (**(code **)(*param_1 + 0xfc))(**(int **)(in_ECX + 0x184) + 0x16c);
  uVar4 = 1;
  if (1 < uVar1) {
    do {
      uVar3 = (**(code **)(*param_1 + 0xfc))(*(int *)(*(int *)(in_ECX + 0x184) + uVar4 * 4) + 0x16c)
      ;
      if (uVar2 != uVar3) {
        if (uVar2 < uVar3) {
          uVar2 = uVar3;
        }
        OutputDebugStringA(&DAT_00c55270);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  return uVar2;
}

