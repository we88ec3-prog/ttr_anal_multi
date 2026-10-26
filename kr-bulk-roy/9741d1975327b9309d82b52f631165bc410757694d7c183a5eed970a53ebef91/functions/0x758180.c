
/* WARNING: Removing unreachable block (ram,0x00758522) */
/* WARNING: Removing unreachable block (ram,0x007582ec) */
/* WARNING: Removing unreachable block (ram,0x00758300) */
/* WARNING: Removing unreachable block (ram,0x0075831d) */
/* WARNING: Removing unreachable block (ram,0x00758320) */
/* WARNING: Removing unreachable block (ram,0x00758329) */
/* WARNING: Removing unreachable block (ram,0x0075832b) */
/* WARNING: Removing unreachable block (ram,0x0075835d) */
/* WARNING: Removing unreachable block (ram,0x007583c2) */
/* WARNING: Removing unreachable block (ram,0x007583c9) */
/* WARNING: Removing unreachable block (ram,0x007583db) */
/* WARNING: Removing unreachable block (ram,0x007583e5) */
/* WARNING: Removing unreachable block (ram,0x007583f8) */
/* WARNING: Removing unreachable block (ram,0x007583f4) */
/* WARNING: Removing unreachable block (ram,0x007583fa) */
/* WARNING: Removing unreachable block (ram,0x007583fe) */
/* WARNING: Removing unreachable block (ram,0x00758400) */
/* WARNING: Removing unreachable block (ram,0x0075840c) */
/* WARNING: Removing unreachable block (ram,0x00758413) */
/* WARNING: Removing unreachable block (ram,0x00758363) */
/* WARNING: Removing unreachable block (ram,0x00758371) */
/* WARNING: Removing unreachable block (ram,0x00758381) */
/* WARNING: Removing unreachable block (ram,0x0075838b) */
/* WARNING: Removing unreachable block (ram,0x0075839e) */
/* WARNING: Removing unreachable block (ram,0x0075839a) */
/* WARNING: Removing unreachable block (ram,0x007583a0) */
/* WARNING: Removing unreachable block (ram,0x007583a4) */
/* WARNING: Removing unreachable block (ram,0x007583a6) */
/* WARNING: Removing unreachable block (ram,0x007583b2) */
/* WARNING: Removing unreachable block (ram,0x007583b9) */
/* WARNING: Removing unreachable block (ram,0x00758418) */
/* WARNING: Removing unreachable block (ram,0x00758426) */
/* WARNING: Removing unreachable block (ram,0x0075848e) */
/* WARNING: Removing unreachable block (ram,0x00758495) */
/* WARNING: Removing unreachable block (ram,0x007584a7) */
/* WARNING: Removing unreachable block (ram,0x007584b1) */
/* WARNING: Removing unreachable block (ram,0x007584c4) */
/* WARNING: Removing unreachable block (ram,0x007584c0) */
/* WARNING: Removing unreachable block (ram,0x007584c6) */
/* WARNING: Removing unreachable block (ram,0x007584ca) */
/* WARNING: Removing unreachable block (ram,0x007584cc) */
/* WARNING: Removing unreachable block (ram,0x007584db) */
/* WARNING: Removing unreachable block (ram,0x007584e2) */
/* WARNING: Removing unreachable block (ram,0x0075842c) */
/* WARNING: Removing unreachable block (ram,0x0075843a) */
/* WARNING: Removing unreachable block (ram,0x00758550) */
/* WARNING: Removing unreachable block (ram,0x0075844a) */
/* WARNING: Removing unreachable block (ram,0x00758454) */
/* WARNING: Removing unreachable block (ram,0x00758467) */
/* WARNING: Removing unreachable block (ram,0x00758463) */
/* WARNING: Removing unreachable block (ram,0x00758469) */
/* WARNING: Removing unreachable block (ram,0x0075846d) */
/* WARNING: Removing unreachable block (ram,0x0075846f) */
/* WARNING: Removing unreachable block (ram,0x0075847e) */
/* WARNING: Removing unreachable block (ram,0x00758485) */
/* WARNING: Removing unreachable block (ram,0x007584e7) */
/* WARNING: Removing unreachable block (ram,0x007584f3) */
/* WARNING: Removing unreachable block (ram,0x00758504) */
/* WARNING: Removing unreachable block (ram,0x00758518) */
/* WARNING: Removing unreachable block (ram,0x00758533) */

void FUN_00758180(undefined4 *param_1,uint *param_2,uint *param_3,int *param_4,int *param_5,
                 int param_6,uint param_7)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  undefined1 local_34 [16];
  int local_24 [5];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar4 = param_6;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009058c0;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_7 & 0x10) == 0) {
    iVar4 = 0;
    param_4 = (int *)in_ECX;
    if (0 < param_6) {
      do {
        puVar3 = param_1;
        if (7 < (uint)param_1[5]) {
          puVar3 = (undefined4 *)*param_1;
        }
        if (*(short *)((int)puVar3 + iVar4 * 2) == 10) {
          puVar3 = (undefined4 *)param_2[1];
          if ((&param_4 < puVar3) && (puVar1 = (undefined4 *)*param_2, puVar1 <= &param_4)) {
            if (puVar3 == (undefined4 *)param_2[2]) {
              FUN_006d6240(uVar2);
            }
            if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
              *(undefined4 *)param_2[1] =
                   *(undefined4 *)(*param_2 + ((int)&param_4 - (int)puVar1 >> 2) * 4);
            }
          }
          else {
            if (puVar3 == (undefined4 *)param_2[2]) {
              FUN_006d6240(uVar2);
            }
            if ((int *)param_2[1] != (int *)0x0) {
              *(int *)param_2[1] = in_ECX;
            }
          }
          param_2[1] = param_2[1] + 4;
          puVar3 = (undefined4 *)param_3[1];
          iVar5 = iVar4 - in_ECX;
          param_4 = (int *)iVar5;
          if (&param_4 < puVar3) {
            puVar1 = (undefined4 *)*param_3;
            if (&param_4 < puVar1) goto LAB_0075863e;
            if (puVar3 == (undefined4 *)param_3[2]) {
              FUN_006d6240(uVar2);
            }
            if ((undefined4 *)param_3[1] != (undefined4 *)0x0) {
              *(undefined4 *)param_3[1] =
                   *(undefined4 *)(*param_3 + ((int)&param_4 - (int)puVar1 >> 2) * 4);
            }
          }
          else {
LAB_0075863e:
            if (puVar3 == (undefined4 *)param_3[2]) {
              FUN_006d6240(uVar2);
            }
            if ((int *)param_3[1] != (int *)0x0) {
              *(int *)param_3[1] = iVar5;
            }
          }
          param_3[1] = param_3[1] + 4;
          in_ECX = iVar4 + 1;
          param_4 = (int *)in_ECX;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_6);
    }
    FUN_004a8680();
    FUN_004a8680();
  }
  else {
    puVar3 = param_1;
    if (7 < (uint)param_1[5]) {
      puVar3 = (undefined4 *)*param_1;
    }
    (**(code **)(*param_4 + 0x30))(local_24,local_34,(int)puVar3 + in_ECX * 2,1);
    if (param_5[2] - *param_5 < local_24[0]) {
      if (in_ECX < iVar4) {
        do {
          puVar3 = param_1;
          if (7 < (uint)param_1[5]) {
            puVar3 = (undefined4 *)*param_1;
          }
          if (*(short *)((int)puVar3 + in_ECX * 2) != 10) {
            param_6 = in_ECX;
            FUN_004a8680();
            param_4 = (int *)0x1;
            FUN_004a8680();
            in_ECX = param_6;
          }
          in_ECX = in_ECX + 1;
        } while (in_ECX < iVar4);
        ExceptionList = local_10;
        return;
      }
    }
    else {
      local_8 = 1;
      iVar5 = 0;
      param_6 = in_ECX;
      if (0 < iVar4) {
        do {
          puVar3 = param_1;
          if (7 < (uint)param_1[5]) {
            puVar3 = (undefined4 *)*param_1;
          }
          if (*(short *)((int)puVar3 + iVar5 * 2) == 10) {
            FUN_004a8680();
            param_6 = iVar5 - param_6;
            FUN_004a8680();
            param_6 = iVar5 + 1;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar4);
      }
      FUN_004a8680();
      param_6 = iVar4 - param_6;
      FUN_004a8680();
    }
  }
  ExceptionList = local_10;
  return;
}

