
void FUN_0087ac20(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_EBX;
  int *piVar3;
  int *unaff_ESI;
  int *piVar4;
  uint uVar5;
  int *local_11c;
  undefined4 local_118;
  int *local_114;
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_11c;
  local_118 = param_2;
  local_11c = param_4;
  if (param_4[7] == -1) {
    __security_check_cookie(local_c ^ (uint)&local_11c);
    return;
  }
  piVar3 = *(int **)(param_1 + 4);
  local_114 = piVar3;
  if (piVar3 != DAT_00fba940) {
    if (DAT_00fba940 != (int *)0x0) {
      (**(code **)(*DAT_00fba940 + 0x10c))(DAT_00fba940);
      DAT_00fba940 = (int *)0x0;
    }
    iVar1 = *(int *)(param_5 + 0x3c);
    if (*(int *)(iVar1 + 0x408) != 0) {
      puVar2 = (undefined4 *)(iVar1 + 0x3f8);
      if (0xf < *(uint *)(iVar1 + 0x40c)) {
        puVar2 = (undefined4 *)*puVar2;
      }
      if (puVar2 != (undefined4 *)0x0) {
        (**(code **)(*piVar3 + 0xe8))(piVar3,puVar2);
      }
    }
    (**(code **)(*piVar3 + 0xfc))(piVar3,0,0);
    DAT_00fba940 = piVar3;
  }
  (**(code **)(*piVar3 + 0x100))(piVar3,param_4[7]);
  _sprintf((char *)&local_118,"\nG-Blender : Begin Pass [%d]",param_4[7]);
  if (*(int *)(param_5 + 0x40) == 1) {
    piVar4 = (int *)param_4[3];
    if ((piVar4 != (int *)0x0) &&
       (iVar1 = piVar4[1] - *piVar4 >> 0x1f, uVar5 = 0, param_4 = unaff_ESI,
       (piVar4[1] - *piVar4) / 0x78 + iVar1 != iVar1)) {
      do {
        if ((uint)((piVar4[1] - *piVar4) / 0x78) <= uVar5) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db7d("invalid vector<T> subscript");
        }
        FUN_0083d3a0(unaff_EBX);
        piVar4 = (int *)unaff_ESI[3];
        uVar5 = uVar5 + 1;
        piVar3 = local_11c;
      } while (uVar5 < (uint)((piVar4[1] - *piVar4) / 0x78));
    }
  }
  else if (*(int *)(param_5 + 0x40) == 2) {
    FUN_0083dd10();
  }
  (**(code **)(*piVar3 + 0x108))(piVar3);
  _sprintf((char *)&local_11c,"\nG-Blender : End Pass [%d]",param_4[7]);
  __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffed8);
  return;
}

