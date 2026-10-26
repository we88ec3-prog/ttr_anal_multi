
void FUN_00632b10(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int local_34;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946536;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_8 = 0;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  iVar3 = DAT_00fb114c;
  local_8 = 0xffffffff;
  FUN_00503d20();
  if (((local_34 != *(int *)(iVar3 + 4)) && (local_34 != -0x10)) &&
     (piVar6 = (int *)**(int **)(local_34 + 0x7c), piVar6 != *(int **)(local_34 + 0x7c))) {
    do {
      FUN_004026e0(piVar6 + 4,0,0xffffffff);
      FUN_00633f80();
      local_8 = 1;
      FUN_004041f0();
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c();
      }
      local_1c = 7;
      FUN_00404300();
      if (*(char *)((int)piVar6 + 0x2d) == '\0') {
        piVar2 = (int *)piVar6[2];
        if (*(char *)((int)piVar2 + 0x2d) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x2d);
            piVar6 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x2d);
          piVar4 = (int *)piVar6[1];
          piVar2 = piVar6;
          while ((piVar6 = piVar4, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x2d);
            piVar4 = (int *)piVar6[1];
            piVar2 = piVar6;
          }
        }
      }
    } while (piVar6 != *(int **)(local_34 + 0x7c));
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar5 ^ (uint)&stack0xfffffffc);
  return;
}

