
/* WARNING: Removing unreachable block (ram,0x00536928) */
/* WARNING: Removing unreachable block (ram,0x00536938) */
/* WARNING: Removing unreachable block (ram,0x00536941) */
/* WARNING: Removing unreachable block (ram,0x00536944) */
/* WARNING: Removing unreachable block (ram,0x00536934) */
/* WARNING: Removing unreachable block (ram,0x00536952) */
/* WARNING: Removing unreachable block (ram,0x00536962) */
/* WARNING: Removing unreachable block (ram,0x0053696d) */
/* WARNING: Removing unreachable block (ram,0x00536969) */
/* WARNING: Removing unreachable block (ram,0x0053695d) */
/* WARNING: Removing unreachable block (ram,0x00536970) */

void FUN_00536860(undefined4 *param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  
  if (*(char *)((int)param_2 + 0x31) != '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid map/set<T> iterator");
  }
  FUN_0050ef70();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x31) == '\0') {
    if (*(char *)(param_2[2] + 0x31) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x31) == '\0') {
    piVar7[1] = (int)piVar6;
  }
  if ((int *)DAT_00fe36f4[1] == param_2) {
    DAT_00fe36f4[1] = piVar7;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar7;
  }
  else {
    piVar6[2] = (int)piVar7;
  }
  if ((int *)*DAT_00fe36f4 == param_2) {
    piVar5 = piVar6;
    if (*(char *)((int)piVar7 + 0x31) == '\0') {
      cVar1 = *(char *)(*piVar7 + 0x31);
      piVar2 = (int *)*piVar7;
      piVar5 = piVar7;
      while (piVar3 = piVar2, cVar1 == '\0') {
        piVar2 = (int *)*piVar3;
        cVar1 = *(char *)((int)piVar2 + 0x31);
        piVar5 = piVar3;
      }
    }
    *DAT_00fe36f4 = piVar5;
  }
  if ((int *)DAT_00fe36f4[2] == param_2) {
    if (*(char *)((int)piVar7 + 0x31) == '\0') {
      uVar4 = FUN_0050eeb0();
      DAT_00fe36f4[2] = uVar4;
    }
    else {
      DAT_00fe36f4[2] = piVar6;
    }
  }
  if ((char)param_2[0xc] == '\x01') {
    if (piVar7 != (int *)DAT_00fe36f4[1]) {
      do {
        piVar5 = piVar6;
        if ((char)piVar7[0xc] != '\x01') break;
        piVar6 = (int *)*piVar5;
        if (piVar7 == piVar6) {
          piVar6 = (int *)piVar5[2];
          if ((char)piVar6[0xc] == '\0') {
            *(undefined1 *)(piVar6 + 0xc) = 1;
            *(undefined1 *)(piVar5 + 0xc) = 0;
            FUN_00536b20();
            piVar6 = (int *)piVar5[2];
          }
          if (*(char *)((int)piVar6 + 0x31) == '\0') {
            if ((*(char *)(*piVar6 + 0x30) != '\x01') || (*(char *)(piVar6[2] + 0x30) != '\x01')) {
              if (*(char *)(piVar6[2] + 0x30) == '\x01') {
                *(undefined1 *)(*piVar6 + 0x30) = 1;
                *(undefined1 *)(piVar6 + 0xc) = 0;
                FUN_00536b70();
                piVar6 = (int *)piVar5[2];
              }
              *(char *)(piVar6 + 0xc) = (char)piVar5[0xc];
              *(undefined1 *)(piVar5 + 0xc) = 1;
              *(undefined1 *)(piVar6[2] + 0x30) = 1;
              FUN_00536b20();
              break;
            }
LAB_00536a3b:
            *(undefined1 *)(piVar6 + 0xc) = 0;
          }
        }
        else {
          if ((char)piVar6[0xc] == '\0') {
            *(undefined1 *)(piVar6 + 0xc) = 1;
            *(undefined1 *)(piVar5 + 0xc) = 0;
            FUN_00536b70();
            piVar6 = (int *)*piVar5;
          }
          if (*(char *)((int)piVar6 + 0x31) == '\0') {
            if ((*(char *)(piVar6[2] + 0x30) == '\x01') && (*(char *)(*piVar6 + 0x30) == '\x01'))
            goto LAB_00536a3b;
            if (*(char *)(*piVar6 + 0x30) == '\x01') {
              *(undefined1 *)(piVar6[2] + 0x30) = 1;
              *(undefined1 *)(piVar6 + 0xc) = 0;
              FUN_00536b20();
              piVar6 = (int *)*piVar5;
            }
            *(char *)(piVar6 + 0xc) = (char)piVar5[0xc];
            *(undefined1 *)(piVar5 + 0xc) = 1;
            *(undefined1 *)(*piVar6 + 0x30) = 1;
            FUN_00536b70();
            break;
          }
        }
        piVar6 = (int *)piVar5[1];
        piVar7 = piVar5;
      } while (piVar5 != (int *)DAT_00fe36f4[1]);
    }
    *(undefined1 *)(piVar7 + 0xc) = 1;
  }
  if (7 < (uint)param_2[9]) {
    FUN_0089120c(param_2[4]);
  }
  param_2[9] = 7;
  param_2[8] = 0;
  *(undefined2 *)(param_2 + 4) = 0;
  FUN_0089120c(param_2);
  if (DAT_00fe36f8 != 0) {
    DAT_00fe36f8 = DAT_00fe36f8 + -1;
  }
  *param_1 = param_2;
  return;
}

