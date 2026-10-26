
bool FUN_007037a0(uint param_1,byte *param_2)

{
  byte bVar1;
  int in_EAX;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint _C;
  bool bVar6;
  
  bVar6 = *(char *)(in_EAX + 1) == '^';
  if (bVar6) {
    in_EAX = in_EAX + 1;
  }
  bVar6 = !bVar6;
  pbVar5 = (byte *)(in_EAX + 1);
  if (pbVar5 < param_2) {
    pbVar2 = (byte *)(in_EAX + 3);
    do {
      if (*pbVar5 == 0x25) {
        _C = (uint)pbVar5[1];
        pbVar5 = pbVar5 + 1;
        pbVar2 = pbVar2 + 1;
        iVar3 = _tolower(_C);
        switch(iVar3) {
        case 0x61:
          uVar4 = _isalpha(param_1);
          break;
        default:
          uVar4 = (uint)(_C == param_1);
          goto LAB_007038ac;
        case 99:
          uVar4 = _iscntrl(param_1);
          break;
        case 100:
          uVar4 = _isdigit(param_1);
          break;
        case 0x6c:
          uVar4 = _islower(param_1);
          break;
        case 0x70:
          uVar4 = _ispunct(param_1);
          break;
        case 0x73:
          uVar4 = _isspace(param_1);
          break;
        case 0x75:
          uVar4 = _isupper(param_1);
          break;
        case 0x77:
          uVar4 = _isalnum(param_1);
          break;
        case 0x78:
          uVar4 = _isxdigit(param_1);
          break;
        case 0x7a:
          uVar4 = (uint)(param_1 == 0);
        }
        iVar3 = _islower(_C);
        if (iVar3 == 0) {
          uVar4 = (uint)(uVar4 == 0);
        }
LAB_007038ac:
        if (uVar4 != 0) {
          return bVar6;
        }
      }
      else if ((pbVar5[1] == 0x2d) && (pbVar2 < param_2)) {
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + 2;
        pbVar2 = pbVar2 + 2;
        if (((int)(uint)bVar1 <= (int)param_1) && ((int)param_1 <= (int)(uint)*pbVar5)) {
          return bVar6;
        }
      }
      else if (*pbVar5 == param_1) {
        return bVar6;
      }
      pbVar5 = pbVar5 + 1;
      pbVar2 = pbVar2 + 1;
    } while (pbVar5 < param_2);
  }
  return !bVar6;
}

