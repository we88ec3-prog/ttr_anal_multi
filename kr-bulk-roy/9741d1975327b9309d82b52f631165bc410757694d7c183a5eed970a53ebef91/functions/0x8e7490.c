
void FUN_008e7490(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  size_t _Size;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *_Dst;
  void *local_10;
  size_t local_c;
  int local_8;
  
  piVar3 = param_2;
  puVar2 = *(undefined4 **)(param_1 + 0x1e8);
  local_8 = param_2[4];
  piVar1 = param_2 + 0x4f;
  (*(code *)param_2[7])(param_2);
  if (((char *)*piVar3 < (char *)piVar3[2]) && (*(char *)*piVar3 == '[')) {
    (*(code *)piVar3[8])(piVar3);
    (*(code *)piVar3[7])(piVar3);
    if (((char *)piVar3[2] <= (char *)*piVar3) || (*(char *)*piVar3 != ']')) {
      piVar3[3] = 3;
      return;
    }
  }
  else {
    iVar4 = (*(code *)piVar3[9])(piVar3);
    (*(code *)piVar3[8])(piVar3);
    if (piVar3[3] == 0) {
      (*(code *)piVar3[7])(piVar3);
      if ((piVar3[0x4e] == 0) &&
         (param_2 = (int *)(**(code **)*puVar2)(piVar1,iVar4,local_8), param_2 != (int *)0x0)) {
LAB_008e76cf:
        piVar3[3] = (int)param_2;
        return;
      }
      if (*piVar3 + 4U < (uint)piVar3[2]) {
        do {
          iVar5 = _strncmp((char *)*piVar3,"dup",3);
          if (iVar5 != 0) break;
          (*(code *)piVar3[8])(piVar3);
          uVar6 = (*(code *)piVar3[9])(piVar3);
          iVar5 = FUN_008e7060(&local_c,&local_10,*(int *)(*(int *)(param_1 + 0x80) + 0x30) != 0);
          if (iVar5 == 0) {
            return;
          }
          (*(code *)piVar3[8])(piVar3);
          if (piVar3[3] != 0) {
            return;
          }
          (*(code *)piVar3[7])(piVar3);
          if (((char *)*piVar3 + 4 < (char *)piVar3[2]) &&
             (iVar5 = _strncmp((char *)*piVar3,"put",3), iVar5 == 0)) {
            (*(code *)piVar3[8])(piVar3);
            (*(code *)piVar3[7])(piVar3);
          }
          _Size = local_c;
          if (piVar3[0x4e] == 0) {
            if (*(int *)(param_1 + 0xac) < 0) {
              param_2 = (int *)(*(code *)piVar3[0x5a])(piVar3 + 0x4f,uVar6,local_10,local_c);
            }
            else {
              if ((int)local_c < *(int *)(param_1 + 0xac)) {
                param_2 = (int *)0x3;
                goto LAB_008e76cf;
              }
              _Dst = (void *)FUN_008baee0(local_8,local_c,&param_2);
              if (param_2 != (int *)0x0) goto LAB_008e76cf;
              FID_conflict__memcpy(_Dst,local_10,_Size);
              (*(code *)puVar2[4])(_Dst,_Size,0x10ea);
              local_c = _Size - *(int *)(param_1 + 0xac);
              param_2 = (int *)(*(code *)piVar3[0x5a])
                                         (piVar3 + 0x4f,uVar6,*(int *)(param_1 + 0xac) + (int)_Dst,
                                          local_c);
              FUN_008b9f80(local_8,_Dst);
            }
            if (param_2 != (int *)0x0) goto LAB_008e76cf;
          }
        } while (*piVar3 + 4U < (uint)piVar3[2]);
      }
      if (piVar3[0x4e] == 0) {
        piVar3[0x4e] = iVar4;
      }
    }
  }
  return;
}

