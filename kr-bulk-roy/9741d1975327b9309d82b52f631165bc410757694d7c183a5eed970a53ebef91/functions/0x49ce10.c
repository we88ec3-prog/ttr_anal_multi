
void FUN_0049ce10(int *param_1,char param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int in_ECX;
  int *piVar7;
  int *piVar8;
  int local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936f3c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(*(int *)(in_ECX + 0x158) + 8) != 3) {
    local_28 = *(float *)(in_ECX + 0xa0);
    local_24 = *(float *)(in_ECX + 0xa4);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0;
      FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fVar4 = DAT_00fb90bc * *(float *)(in_ECX + 0xb4);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    piVar8 = (int *)*DAT_00fab13c;
    piVar7 = DAT_00fab13c;
    if (piVar8 != DAT_00fab13c) {
      do {
        local_2c = piVar8[4];
        if ((*(char *)(local_2c + 4) == '\x03') &&
           ((param_2 == '\0' || (*(int *)(local_2c + 0x11c) != 0)))) {
          local_20 = *(float *)(local_2c + 0xa0) - local_28;
          local_1c = *(float *)(local_2c + 0xa4) - local_24;
          if (local_20 * local_20 + local_1c * local_1c < fVar4 * fVar4 + 100.0) {
            iVar2 = *param_1;
            iVar6 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_2c);
            if (param_1[1] == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("list<T> too long");
            }
            param_1[1] = param_1[1] + 1;
            *(int *)(iVar2 + 4) = iVar6;
            **(int **)(iVar6 + 4) = iVar6;
            piVar7 = DAT_00fab13c;
          }
        }
        if (*(char *)((int)piVar8 + 0x15) == '\0') {
          piVar3 = (int *)piVar8[2];
          if (*(char *)((int)piVar3 + 0x15) == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar8 = piVar3;
            piVar3 = (int *)*piVar3;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar3 + 0x15);
              piVar8 = piVar3;
              piVar3 = (int *)*piVar3;
            }
          }
          else {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar5 = (int *)piVar8[1];
            piVar3 = piVar8;
            while ((piVar8 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar8[2]))) {
              cVar1 = *(char *)(piVar8[1] + 0x15);
              piVar5 = (int *)piVar8[1];
              piVar3 = piVar8;
            }
          }
        }
      } while (piVar8 != piVar7);
    }
  }
  ExceptionList = local_14;
  return;
}

