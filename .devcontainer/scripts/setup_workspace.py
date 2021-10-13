#!/usr/bin/python3

from logging import info

import argparse
import logging
import sys
import typing


def main(args: argparse.Namespace) -> None:
    logging.basicConfig(
        format='[%(levelname)s] %(message)s',
        level=logging.INFO,
    )
    info('start setup')
    info('finish setup')


def parse_args(app_name: str, argv: typing.List[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(app_name)
    args = parser.parse_args(argv)
    return args


if '__main__' == __name__:
    args = parse_args(sys.argv[0], sys.argv[1:])
    main(args)
