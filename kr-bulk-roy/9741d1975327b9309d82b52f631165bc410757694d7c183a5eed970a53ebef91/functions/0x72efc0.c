
/* WARNING: Type propagation algorithm not settling */

void FUN_0072efc0(int *param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 *******pppppppuVar4;
  char *in_ECX;
  char *pcVar5;
  undefined4 *******local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917838;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 *******)((uint)local_30[0] & 0xffffff00);
  local_8 = 0;
  local_14 = uVar3;
  if ((param_2 != 0xf) && (cVar2 = FUN_00402f80(param_2,1), cVar2 != '\0')) {
    local_20 = 0;
    pppppppuVar4 = local_30[0];
    if (local_1c < 0x10) {
      pppppppuVar4 = local_30;
    }
    *(undefined1 *)pppppppuVar4 = 0;
  }
  pcVar5 = in_ECX + param_2;
  pcVar1 = in_ECX;
joined_r0x0072f038:
  do {
    while( true ) {
      if ((pcVar5 <= in_ECX) || (cVar2 = *in_ECX, cVar2 == '\0')) {
        if ((int)in_ECX - (int)pcVar1 != 0) {
          FUN_00401fc0(pcVar1,(int)in_ECX - (int)pcVar1);
        }
        pppppppuVar4 = local_30[0];
        if (local_1c < 0x10) {
          pppppppuVar4 = local_30;
        }
        (**(code **)(*param_1 + 8))(pppppppuVar4,0,param_3,uVar3);
        if ((char)param_1[0x11] == '\0') {
          if (0xf < local_1c) {
            FUN_0089120c(local_30[0]);
          }
        }
        else if (0xf < local_1c) {
          FUN_0089120c(local_30[0]);
        }
        ExceptionList = local_10;
        __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
        return;
      }
      if (cVar2 != '\n') break;
      FUN_00401fc0(pcVar1,in_ECX + (1 - (int)pcVar1));
LAB_0072f059:
      in_ECX = in_ECX + 1;
      pcVar1 = in_ECX;
    }
    if (cVar2 == '\r') {
      if (0 < (int)in_ECX - (int)pcVar1) {
        FUN_00401fc0(pcVar1,(int)in_ECX - (int)pcVar1);
      }
      FUN_00429630(1,10);
      if (in_ECX[1] != '\n') goto LAB_0072f059;
      in_ECX = in_ECX + 2;
      pcVar1 = in_ECX;
      goto joined_r0x0072f038;
    }
    in_ECX = in_ECX + 1;
  } while( true );
}

