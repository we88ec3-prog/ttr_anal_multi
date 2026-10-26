
char * FUN_008e8760(int param_1,undefined4 param_2,uint param_3,undefined4 *param_4,int param_5)

{
  char cVar1;
  char *pcVar2;
  size_t _Size;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  
  pcVar5 = (char *)0xffffffff;
  switch(param_2) {
  case 0:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x1b1);
      return (char *)0x1;
    }
    break;
  case 1:
    if (param_3 < 4) {
      uVar4 = 0;
      pcVar5 = (char *)0x4;
      if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
        switch(param_3) {
        case 0:
          *param_4 = *(undefined4 *)(param_1 + 0x1b4);
          return (char *)0x4;
        case 1:
          *param_4 = *(undefined4 *)(param_1 + 0x1b8);
          return (char *)0x4;
        case 2:
          *param_4 = *(undefined4 *)(param_1 + 0x1bc);
          return (char *)0x4;
        case 3:
          uVar4 = *(undefined4 *)(param_1 + 0x1c0);
        }
        *param_4 = uVar4;
        return (char *)0x4;
      }
    }
    break;
  case 2:
    if (param_3 < 4) {
      uVar4 = 0;
      pcVar5 = (char *)0x4;
      if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
        switch(param_3) {
        case 0:
          *param_4 = *(undefined4 *)(param_1 + 0x1cc);
          return (char *)0x4;
        case 1:
          *param_4 = *(undefined4 *)(param_1 + 0x1d0);
          return (char *)0x4;
        case 2:
          *param_4 = *(undefined4 *)(param_1 + 0x1d4);
          return (char *)0x4;
        case 3:
          uVar4 = *(undefined4 *)(param_1 + 0x1d8);
        }
        *param_4 = uVar4;
        return (char *)0x4;
      }
    }
    break;
  case 3:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x1b0);
      return (char *)0x1;
    }
    break;
  case 4:
    pcVar2 = *(char **)(param_1 + 0x16c);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    goto LAB_008e8fdb;
  case 5:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0xa8);
      return (char *)0x4;
    }
    break;
  case 6:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x1a0);
      return (char *)0x4;
    }
    break;
  case 7:
    if (param_3 < *(uint *)(param_1 + 0x1a0)) {
      pcVar6 = *(char **)(*(int *)(param_1 + 0x1a4) + param_3 * 4);
      pcVar2 = pcVar6;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar5 = (char *)(((int)pcVar2 - (int)(pcVar6 + 1)) + 1);
      if ((param_4 != (undefined4 *)0x0) && ((int)pcVar5 <= param_5)) {
        FID_conflict__memcpy(param_4,pcVar6,(size_t)pcVar5);
        *(undefined1 *)(((int)pcVar2 - (int)(pcVar6 + 1)) + (int)param_4) = 0;
        return pcVar5;
      }
    }
    break;
  case 8:
    if (((param_3 < *(uint *)(param_1 + 0x1a0)) &&
        (pcVar5 = (char *)(*(int *)(*(int *)(param_1 + 0x1ac) + param_3 * 4) + 1),
        param_4 != (undefined4 *)0x0)) && ((int)pcVar5 <= param_5)) {
      iVar3 = *(int *)(param_1 + 0x1a8);
LAB_008e8a86:
      FID_conflict__memcpy(param_4,*(void **)(iVar3 + param_3 * 4),(size_t)(pcVar5 + -1));
      (pcVar5 + -1)[(int)param_4] = '\0';
      return pcVar5;
    }
    break;
  case 9:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x170);
      return (char *)0x4;
    }
    break;
  case 10:
    if ((*(int *)(param_1 + 0x170) == 1) && (param_3 < *(uint *)(param_1 + 0x174))) {
      pcVar6 = *(char **)(*(int *)(param_1 + 0x184) + param_3 * 4);
      pcVar5 = pcVar6;
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      _Size = (int)pcVar5 - (int)(pcVar6 + 1);
      pcVar5 = (char *)(_Size + 1);
      if ((param_4 != (undefined4 *)0x0) && ((int)pcVar5 <= param_5)) {
        FID_conflict__memcpy(param_4,pcVar6,_Size);
        *(undefined1 *)(_Size + (int)param_4) = 0;
        return pcVar5;
      }
    }
    break;
  case 0xb:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x194);
      return (char *)0x4;
    }
    break;
  case 0xc:
    if (((param_3 < *(uint *)(param_1 + 0x194)) &&
        (pcVar5 = (char *)(*(int *)(*(int *)(param_1 + 0x19c) + param_3 * 4) + 1),
        param_4 != (undefined4 *)0x0)) && ((int)pcVar5 <= param_5)) {
      iVar3 = *(int *)(param_1 + 0x198);
      goto LAB_008e8a86;
    }
    break;
  case 0xd:
    pcVar5 = (char *)0x2;
    if ((param_4 != (undefined4 *)0x0) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x120);
      return (char *)0x2;
    }
    break;
  case 0xe:
    pcVar5 = (char *)0x2;
    if ((param_4 != (undefined4 *)0x0) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x122);
      return (char *)0x2;
    }
    break;
  case 0xf:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0xb0);
      return (char *)0x1;
    }
    break;
  case 0x10:
    if (((param_3 < *(byte *)(param_1 + 0xb0)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0xb4 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x11:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x11c);
      return (char *)0x4;
    }
    break;
  case 0x12:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0xb1);
      return (char *)0x1;
    }
    break;
  case 0x13:
    if (((param_3 < *(byte *)(param_1 + 0xb1)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0xd0 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x14:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0xb2);
      return (char *)0x1;
    }
    break;
  case 0x15:
    if (((param_3 < *(byte *)(param_1 + 0xb2)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0xe4 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x16:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0xb3);
      return (char *)0x1;
    }
    break;
  case 0x17:
    if (((param_3 < *(byte *)(param_1 + 0xb3)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x100 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x18:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x114);
      return (char *)0x4;
    }
    break;
  case 0x19:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x118);
      return (char *)0x4;
    }
    break;
  case 0x1a:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x124);
      return (char *)0x1;
    }
    break;
  case 0x1b:
    if (((param_3 < *(byte *)(param_1 + 0x124)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x128 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x1c:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x125);
      return (char *)0x1;
    }
    break;
  case 0x1d:
    if (((param_3 < *(byte *)(param_1 + 0x125)) &&
        (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x142 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x1e:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x126);
      return (char *)0x1;
    }
    break;
  case 0x1f:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x127);
      return (char *)0x1;
    }
    break;
  case 0x20:
    if (((param_3 < 2) && (pcVar5 = (char *)0x2, param_4 != (undefined4 *)0x0)) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x168 + param_3 * 2);
      return (char *)0x2;
    }
    break;
  case 0x21:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0xac);
      return (char *)0x4;
    }
    break;
  case 0x22:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x164);
      return (char *)0x4;
    }
    break;
  case 0x23:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x160);
      return (char *)0x4;
    }
    break;
  case 0x24:
    pcVar2 = *(char **)(param_1 + 0x84);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    goto LAB_008e8fdb;
  case 0x25:
    pcVar2 = *(char **)(param_1 + 0x88);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    goto LAB_008e8fdb;
  case 0x26:
    pcVar2 = *(char **)(param_1 + 0x8c);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    goto LAB_008e8fdb;
  case 0x27:
    pcVar2 = *(char **)(param_1 + 0x90);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    goto LAB_008e8fdb;
  case 0x28:
    pcVar2 = *(char **)(param_1 + 0x94);
    pcVar6 = pcVar2 + 1;
    pcVar5 = pcVar2;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
LAB_008e8fdb:
    pcVar5 = pcVar5 + (1 - (int)pcVar6);
    if ((param_4 != (undefined4 *)0x0) && ((int)pcVar5 <= param_5)) {
      FID_conflict__memcpy(param_4,pcVar2,(size_t)pcVar5);
      return pcVar5;
    }
    break;
  case 0x29:
    pcVar5 = (char *)0x1;
    if ((param_4 != (undefined4 *)0x0) && (0 < param_5)) {
      *(undefined1 *)param_4 = *(undefined1 *)(param_1 + 0x9c);
      return (char *)0x1;
    }
    break;
  case 0x2a:
    pcVar5 = (char *)0x2;
    if ((param_4 != (undefined4 *)0x0) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0x9e);
      return (char *)0x2;
    }
    break;
  case 0x2b:
    pcVar5 = (char *)0x2;
    if ((param_4 != (undefined4 *)0x0) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0xa0);
      return (char *)0x2;
    }
    break;
  case 0x2c:
    pcVar5 = (char *)0x2;
    if ((param_4 != (undefined4 *)0x0) && (1 < param_5)) {
      *(undefined2 *)param_4 = *(undefined2 *)(param_1 + 0xa4);
      return (char *)0x2;
    }
    break;
  case 0x2d:
    pcVar5 = (char *)0x4;
    if ((param_4 != (undefined4 *)0x0) && (3 < param_5)) {
      *param_4 = *(undefined4 *)(param_1 + 0x98);
    }
  }
  return pcVar5;
}

