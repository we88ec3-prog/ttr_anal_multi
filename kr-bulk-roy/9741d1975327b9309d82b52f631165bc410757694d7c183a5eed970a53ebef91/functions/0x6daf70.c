
/* WARNING: Removing unreachable block (ram,0x006db10b) */

void FUN_006daf70(int param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  DWORD DVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  uint local_24;
  int iStack_20;
  int *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar9 = param_1;
  if (*(int *)(param_1 + 4) != 0) {
    FUN_006f0220();
    FUN_006f0400();
    local_14 = (int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x48) = 0;
    local_8 = 0;
    do {
      piVar2 = (int *)*local_14;
      piVar7 = (int *)*piVar2;
      local_10 = 0;
      local_c = 0;
      param_1 = 0;
      local_24 = 0;
      iStack_20 = 0;
      if (piVar7 != piVar2) {
        do {
          param_1 = param_1 + piVar7[8];
          uVar8 = piVar7[10];
          bVar10 = CARRY4(local_24,uVar8);
          local_24 = local_24 + uVar8;
          iStack_20 = iStack_20 + piVar7[0xb] + (uint)bVar10;
          if ((param_2 != 0) || (piVar7[6] != 0)) {
            FUN_006f0400(0,
                         "L%d Command [%04d] : \tCount\t%08d\tBytes\t%08d\tTotalCount\t%010d\tTotalBytes\t%010d"
                         ,local_8,(int)(short)piVar7[4],piVar7[6],piVar7[7],piVar7[8],uVar8,
                         piVar7[0xb]);
            local_10 = local_10 + piVar7[6];
            local_c = local_c + piVar7[7];
            piVar7[6] = 0;
            piVar7[7] = 0;
          }
          if (*(char *)((int)piVar7 + 0x31) == '\0') {
            piVar3 = (int *)piVar7[2];
            if (*(char *)((int)piVar3 + 0x31) == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x31);
              piVar7 = piVar3;
              piVar3 = (int *)*piVar3;
              while (cVar1 == '\0') {
                cVar1 = *(char *)(*piVar3 + 0x31);
                piVar7 = piVar3;
                piVar3 = (int *)*piVar3;
              }
            }
            else {
              cVar1 = *(char *)(piVar7[1] + 0x31);
              piVar5 = (int *)piVar7[1];
              piVar3 = piVar7;
              while ((piVar7 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
                cVar1 = *(char *)(piVar7[1] + 0x31);
                piVar5 = (int *)piVar7[1];
                piVar3 = piVar7;
              }
            }
          }
        } while (piVar7 != piVar2);
        if (param_1 != 0) {
          fVar4 = (float)*(int *)(iVar9 + 0x4c);
          if (*(int *)(iVar9 + 0x4c) < 0) {
            fVar4 = fVar4 + 4.2949673e+09;
          }
          DVar6 = timeGetTime();
          uVar8 = (DVar6 - *(int *)(iVar9 + 0x50)) / 1000;
          FUN_006f0400(0,"L%d InPeriod[%dSec]\tCount\t%d\tBytes\t%d\t Cnt/s\t%f\tBytes/s\t%f",
                       local_8,*(undefined4 *)(iVar9 + 0x4c),local_10,local_c,
                       (double)((float)local_10 / fVar4),(double)((float)local_c / fVar4));
          if (uVar8 != 0) {
            FUN_006f0400(0,"L%d Total   [%dSec]\tCount\t%d\tBytes\t%I64d\t Cnt/s\t%f\tBytes/s\t%f",
                         local_8,uVar8,param_1,local_24,iStack_20);
          }
        }
      }
      local_14 = local_14 + 4;
      local_8 = local_8 + 1;
    } while (local_8 < 4);
    FUN_006f0220();
  }
  if (param_2 != 0) {
    iVar9 = iVar9 + 8;
    param_2 = 4;
    do {
      piVar2 = *(int **)(*(int *)(iVar9 + 4) + 4);
      cVar1 = *(char *)((int)piVar2 + 0x31);
      while (cVar1 == '\0') {
        FUN_006db430();
        piVar2 = (int *)*piVar2;
        FUN_0089120c();
        cVar1 = *(char *)((int)piVar2 + 0x31);
      }
      *(int *)(*(int *)(iVar9 + 4) + 4) = *(int *)(iVar9 + 4);
      *(undefined4 *)*(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar9 + 4);
      *(int *)(*(int *)(iVar9 + 4) + 8) = *(int *)(iVar9 + 4);
      *(undefined4 *)(iVar9 + 8) = 0;
      iVar9 = iVar9 + 0x10;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}

