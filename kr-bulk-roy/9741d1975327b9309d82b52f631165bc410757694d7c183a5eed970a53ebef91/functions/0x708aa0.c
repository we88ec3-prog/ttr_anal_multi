
undefined4 FUN_00708aa0(int param_1,FILE *param_2,int param_3)

{
  undefined8 uVar1;
  double *pdVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  int iVar7;
  int *piVar8;
  size_t sVar9;
  undefined4 uVar10;
  size_t local_64;
  void *local_60;
  undefined8 local_50;
  undefined4 local_48;
  
  iVar4 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
  bVar3 = true;
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 == 0) {
      piVar8 = __errno();
      iVar4 = *piVar8;
      if (bVar3) {
        puVar5 = *(undefined4 **)(param_1 + 8);
        *puVar5 = 1;
        puVar5[2] = 1;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        return 1;
      }
      *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      uVar10 = FUN_00898466();
      FUN_006f5580(param_1,&DAT_00bfc638,uVar10);
      pdVar2 = *(double **)(param_1 + 8);
      *pdVar2 = (double)iVar4;
      *(undefined4 *)(pdVar2 + 1) = 3;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      return 3;
    }
    puVar5 = (undefined4 *)FUN_006f50f0();
    if ((puVar5 == &DAT_00c0bfc8) || (puVar5[2] != 3)) {
      piVar8 = (int *)FUN_006f50f0();
      if (piVar8[2] == 4) {
LAB_00708be5:
        local_64 = *(size_t *)(*piVar8 + 0xc);
        local_60 = (void *)(*piVar8 + 0x10);
        if (local_60 == (void *)0x0) goto LAB_00708bf7;
      }
      else {
        iVar7 = FUN_006fb5d0();
        if (iVar7 != 0) {
          if (*(uint *)(*(int *)(param_1 + 0x10) + 0x40) <=
              *(uint *)(*(int *)(param_1 + 0x10) + 0x44)) {
            FUN_006fb3a0();
          }
          piVar8 = (int *)FUN_006f50f0();
          goto LAB_00708be5;
        }
        local_64 = 0;
        local_60 = (void *)0x0;
LAB_00708bf7:
        FUN_006f50f0();
        FUN_006f5580(param_1,"%s expected, got %s","string");
        FUN_006f5da0(param_3);
      }
      if ((!bVar3) || (sVar9 = _fwrite(local_60,1,local_64,param_2), sVar9 != local_64))
      goto LAB_00708b58;
LAB_00708c6b:
      bVar3 = true;
    }
    else {
      if (bVar3) {
        puVar6 = (undefined8 *)FUN_006f50f0();
        if (*(int *)(puVar6 + 1) == 3) {
LAB_00708b37:
          uVar1 = *puVar6;
        }
        else {
          if ((*(int *)(puVar6 + 1) == 4) && (iVar7 = FUN_006f7760(), iVar7 != 0)) {
            local_48 = 3;
            puVar6 = &local_50;
            goto LAB_00708b37;
          }
          uVar1 = 0;
        }
        iVar7 = _fprintf(param_2,"%.14g",uVar1);
        if (0 < iVar7) goto LAB_00708c6b;
      }
LAB_00708b58:
      bVar3 = false;
    }
    param_3 = param_3 + 1;
  } while( true );
}

