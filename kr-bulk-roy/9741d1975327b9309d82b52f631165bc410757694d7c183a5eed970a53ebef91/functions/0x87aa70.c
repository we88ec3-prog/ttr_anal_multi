
void FUN_0087aa70(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iStack_124;
  int iStack_120;
  undefined4 local_11c;
  int local_118;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&iStack_124;
  local_11c = param_2;
  local_118 = param_4;
  if (*(int *)(param_4 + 0xc) != 0) {
    piVar1 = *(int **)(param_1 + 4);
    (**(code **)(*piVar1 + 0xfc))(piVar1,0,0);
    piVar2 = *(int **)(param_4 + 0xc);
    iVar5 = piVar2[1] - *piVar2 >> 0x1f;
    uVar4 = 0;
    if ((piVar2[1] - *piVar2) / 0x78 + iVar5 != iVar5) {
      iVar5 = 0;
      do {
        if ((uint)((piVar2[1] - *piVar2) / 0x78) <= uVar4) {
LAB_0087ac10:
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        iStack_120 = iVar5 + *piVar2;
        uVar3 = 0;
        if (*(int *)(param_5 + 0x44) - *(int *)(param_5 + 0x40) >> 2 != 0) {
          do {
            if ((uint)(*(int *)(param_5 + 0x44) - *(int *)(param_5 + 0x40) >> 2) <= uVar3)
            goto LAB_0087ac10;
            _sprintf((char *)&local_11c,"\nG-Blender : Begin Pass [%d]",
                     *(undefined4 *)(*(int *)(param_5 + 0x40) + uVar3 * 4));
            if ((uint)(*(int *)(param_5 + 0x44) - *(int *)(param_5 + 0x40) >> 2) <= uVar3)
            goto LAB_0087ac10;
            (**(code **)(*piVar1 + 0x100))
                      (piVar1,*(undefined4 *)(*(int *)(param_5 + 0x40) + uVar3 * 4));
            FUN_0083d3a0(uVar4);
            (**(code **)(*piVar1 + 0x108))(piVar1);
            _sprintf((char *)&local_11c,"\nG-Blender : End Pass [%d]",uVar3);
            uVar3 = uVar3 + 1;
          } while (uVar3 < (uint)(*(int *)(param_5 + 0x44) - *(int *)(param_5 + 0x40) >> 2));
        }
        piVar2 = *(int **)(iStack_124 + 0xc);
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 0x78;
      } while (uVar4 < (uint)((piVar2[1] - *piVar2) / 0x78));
    }
    (**(code **)(*piVar1 + 0x10c))(piVar1);
  }
  __security_check_cookie(local_c ^ (uint)&iStack_124);
  return;
}

