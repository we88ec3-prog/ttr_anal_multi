
byte * FUN_007315f0(undefined4 param_1,uint param_2,char *param_3)

{
  char *pcVar1;
  byte bVar2;
  char cVar3;
  byte *in_EAX;
  int iVar4;
  int local_c;
  undefined4 local_8;
  
  FUN_00402a70(&DAT_00bf2375,0);
  if ((char)param_2 == '\0') {
    if (in_EAX != (byte *)0x0) {
      while ((*in_EAX != 0 && (cVar3 = FUN_00731560(0), cVar3 == '\0'))) {
        param_2 = 0;
        in_EAX = (byte *)FUN_00730df0(&local_c);
        FUN_00401fc0(&param_2,local_c);
        if (in_EAX == (byte *)0x0) {
          return (byte *)0x0;
        }
      }
LAB_00731731:
      pcVar1 = param_3 + 1;
      do {
        cVar3 = *param_3;
        param_3 = param_3 + 1;
      } while (cVar3 != '\0');
      return in_EAX + ((int)param_3 - (int)pcVar1);
    }
  }
  else {
    param_2 = param_2 & 0xffffff;
    in_EAX = (byte *)FUN_00731170();
    while (in_EAX != (byte *)0x0) {
      if ((*in_EAX == 0) || (cVar3 = FUN_00731560(0), cVar3 != '\0')) goto LAB_00731731;
      bVar2 = *in_EAX;
      if ((((bVar2 == 0xd) || (bVar2 == 10)) || (iVar4 = _isspace((uint)bVar2), iVar4 != 0)) ||
         ((bVar2 == 10 || (bVar2 == 0xd)))) {
        in_EAX = in_EAX + 1;
        param_2 = CONCAT13(1,(undefined3)param_2);
      }
      else {
        if (param_2._3_1_ != '\0') {
          FUN_00429630(1,0x20);
          param_2 = param_2 & 0xffffff;
        }
        local_8 = 0;
        in_EAX = (byte *)FUN_00730df0(&local_c);
        if (local_c == 1) {
          FUN_00429630(1,local_8);
        }
        else {
          FUN_00401fc0(&local_8,local_c);
        }
      }
    }
  }
  return (byte *)0x0;
}

