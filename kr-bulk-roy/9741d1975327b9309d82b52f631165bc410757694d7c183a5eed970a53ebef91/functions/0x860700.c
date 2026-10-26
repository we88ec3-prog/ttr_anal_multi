
undefined4 FUN_00860700(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 0x74) != 0) {
    FUN_008604e0();
    uVar2 = *(int *)(param_1 + 0x9c) - *(int *)(param_1 + 0x98) >> 2;
    if ((uVar2 != 0) && (param_3 < uVar2)) {
      uVar2 = 0;
      do {
        if ((uint)(param_2[1] - *param_2 >> 2) <= uVar2) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        FUN_0077ef30();
        iVar1 = *(int *)(*(int *)(param_1 + 0x98) + uVar2 * 4);
        FUN_0077ea00();
        uVar2 = uVar2 + 1;
        *(undefined4 *)(iVar1 + 0xc0) = 0;
      } while (uVar2 <= param_3);
      return 1;
    }
  }
  return 0;
}

