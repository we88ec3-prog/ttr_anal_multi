
int FUN_008f05c0(int param_1,uint param_2)

{
  undefined4 uVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_c;
  int local_8;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1c);
  uVar6 = 0;
  local_c = 0;
  local_8 = FUN_008bc7d0(uVar1,2,0,param_2,0,&local_c);
  if (local_c != 0) {
    return 0;
  }
  if (param_2 != 0) {
    do {
      uVar4 = FUN_008b9940(param_1);
      uVar5 = 0;
      if ((char)uVar4 < '\0') {
        do {
          if (param_2 <= uVar6) break;
          *(undefined2 *)(local_8 + uVar6 * 2) = 0;
          uVar5 = uVar5 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar5 <= (uVar4 & 0x3f));
      }
      else if ((uVar4 & 0x40) == 0) {
        do {
          if (param_2 <= uVar6) break;
          cVar2 = FUN_008b9940(param_1);
          *(short *)(local_8 + uVar6 * 2) = (short)cVar2;
          uVar5 = uVar5 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar5 <= (uVar4 & 0x3f));
      }
      else {
        do {
          if (param_2 <= uVar6) break;
          uVar3 = FUN_008b9960(param_1);
          *(undefined2 *)(local_8 + uVar6 * 2) = uVar3;
          uVar5 = uVar5 + 1;
          uVar6 = uVar6 + 1;
        } while (uVar5 <= (uVar4 & 0x3f));
      }
      if (uVar5 <= (uVar4 & 0x3f)) {
        FUN_008b9f80(uVar1,local_8);
        return 0;
      }
    } while (uVar6 < param_2);
  }
  return local_8;
}

