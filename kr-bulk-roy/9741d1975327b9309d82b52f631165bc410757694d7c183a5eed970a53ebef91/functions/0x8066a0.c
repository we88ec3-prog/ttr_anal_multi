
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008066a0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int in_ECX;
  int *piVar8;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009144d6;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CIocpNetwork::vftable;
  local_8 = 0;
  piVar8 = *(int **)param_1[7];
  local_14 = in_ECX;
  if (piVar8 != (int *)param_1[7]) {
    do {
      if (DAT_00fba858 == (undefined *)0x0) {
        if (DAT_00fba85c == 0) {
          if ((DAT_00fc1200 & 1) == 0) {
            DAT_00fc1200 = DAT_00fc1200 | 1;
            local_8._0_1_ = 1;
            FUN_00805460(&DAT_00fc1208);
            _atexit((_func_4879 *)&LAB_00bce670);
            local_8 = (uint)local_8._1_3_ << 8;
          }
          DAT_00fba858 = &DAT_00fc1208;
        }
        else {
          FUN_0049af60(uVar6);
        }
      }
      puVar4 = DAT_00fba858;
      local_14 = piVar8[4];
      *(int *)(DAT_00fba858 + 0x44) = *(int *)(DAT_00fba858 + 0x44) + -1;
      iVar2 = *(int *)(puVar4 + 0x48);
      iVar7 = FUN_0074d700(iVar2,*(undefined4 *)(iVar2 + 4),&local_14);
      if (*(int *)(puVar4 + 0x4c) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("list<T> too long");
      }
      *(int *)(puVar4 + 0x4c) = *(int *)(puVar4 + 0x4c) + 1;
      *(int *)(iVar2 + 4) = iVar7;
      **(int **)(iVar7 + 4) = iVar7;
      *(undefined4 *)(local_14 + 0x14) = 0;
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
    } while (piVar8 != (int *)param_1[7]);
  }
  if ((_DAT_00fe33b4 & 1) == 0) {
    _DAT_00fe33b4 = _DAT_00fe33b4 | 1;
    DAT_00fe33b8 = (HANDLE)0x0;
    _DAT_00fe33bc = 0;
    _DAT_00fe33c0 = 0;
    DAT_00fe33b8 = CreateIoCompletionPort((HANDLE)0xffffffff,(HANDLE)0x0,0,0);
    _atexit((_func_4879 *)&LAB_00bd0bb0);
  }
  FUN_00807f20();
  local_8 = 0xffffffff;
  FUN_00803ec0();
  ExceptionList = local_10;
  return;
}

